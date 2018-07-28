#ifndef MQTTUtils_h
    #define MQTTUtils_h
    #include <PubSubClient.h>
    #include <Utils/WifiUtils.h>
    #include <Utils/PayloadUtils.h>

    class MQTTUtils
    {
        //  const char* mqtt_server = "192.168.1.3";
        static constexpr  char* mqtt_server = "arduino_workshop.akriya.co.in"; //aws s2 dev
        //const char* mqtt_server = "iot.eclipse.org";
        
        public:
            WiFiClient *espClient;
            PubSubClient *client;

            MQTTUtils();
        
            //void callback(char* topic, byte* payload, unsigned int length);
            void reconnect();
            void setup();
            boolean connected();  
            boolean publish(char* topic,char* payload);
    };

#endif