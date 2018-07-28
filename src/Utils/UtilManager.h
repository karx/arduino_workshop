#ifndef UtilManger_h
    #define UtilManger_h

    #include <Utils/MQTTUtils.h>
    #include <Utils/WifiUtils.h>
    #include <Utils/IR_RecvUtils.h>
    #include <Utils/TimeUtils.h>
    #include <Utils/PinUtils.h>

    class UtilManager
    {
        public:
        static MQTTUtils* mqttUtils;
        static IR_RecvUtils* irrUtils;
        static TimeUtils* timeUtils;
        static PinUtils* pinUtils; 

    };

    MQTTUtils* UtilManager::mqttUtils = new MQTTUtils();
    IR_RecvUtils* UtilManager::irrUtils = new IR_RecvUtils();
    TimeUtils* UtilManager::timeUtils = new TimeUtils();
    PinUtils* UtilManager::pinUtils = new PinUtils();

    #endif