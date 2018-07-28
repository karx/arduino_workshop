//to achive states

/*

1   Pin 1 H
2   Timeout 4sec
3   Pin 1 L
4    Timeout 5 secs
5    Pin 2 H
6    Pin 3 H
7    Timeout 2 secs
8    Pin 3 L
9    Pin 2 L
10     Push - < pin 1 T | Timeout 2 Secs | Pin 1 T >

*/


#ifndef State_h
    #define State_h

    #include "Utils/PinUtils.h"
    #include "Utils/TimeUtils.h"
    #include "Utils/UtilManager.h"

    #include "StatePackage/StateTypes.h"
    class State
    {        
        static int totalStateCount;
        int m_stateIndex;
        int m_stateFunctionType; //0 for pin, 1 for Timeout
        int m_arg1Value;
        bool m_arg2Vaue;
        double m_arg3Value;
        char *m_arg4Value;
        TimeUtils stateTimeUtil;
        public:
        static int currentStateIndex;
        

        State(int stateFunctionType,int arg1Value = 0,bool arg2Vaue = false,double arg3Value = 0.0,char* arg4Value = NULL)
        {
            init(stateFunctionType,arg1Value ,arg2Vaue,arg3Value ,arg4Value);
        }
        State(int stateFunctionType,char* arg4Value)
        {
            init(stateFunctionType,0,false,0.0,arg4Value);
        }

        void moveToNextState()
        {
            State::currentStateIndex++;
        }

        bool executeState()
        {
            Serial.print("Current State Value = ");
            Serial.println(State::currentStateIndex);

            switch(m_stateFunctionType)
            {
                case StateTypes::PinState : 
                    UtilManager::pinUtils->setPinState(m_arg1Value,m_arg2Vaue);
                        moveToNextState();                    
                    break;  //not needed if we return true instead of moveToNextState approch
                case StateTypes::TimeoutState :
                {
                    if(stateTimeUtil.timeoutXsec(5))
                        moveToNextState();                    
                    break;
                }
                case StateTypes::MqttPublishState :
                {
                    //MQTT
                    UtilManager::mqttUtils->publish("kaaro/test",m_arg4Value);
                    moveToNextState();
                    break;
                }
                default:
                    Serial.println("dafaq");
                    break;
            }
            return false;
        }

        private:
        void init(int stateFunctionType,int arg1Value = 0,bool arg2Vaue = false,double arg3Value = 0.0,char* arg4Value = NULL)
        {
            m_stateIndex = ++State::totalStateCount;
            m_stateFunctionType = stateFunctionType;
            m_arg1Value = arg1Value;
            m_arg2Vaue = arg2Vaue;
            m_arg3Value = arg3Value;
            m_arg4Value = arg4Value;
        }
    };
    
    int State :: currentStateIndex = 0;
    int State :: totalStateCount = 0;

#endif