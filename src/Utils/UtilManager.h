#ifndef UtilManger_h
    #define UtilManger_h

    #include <Utils/MQTTUtils.h>
    #include <Utils/WifiUtils.h>
    #include <Utils/TimeUtils.h>
    #include <Utils/PinUtils.h>

    class UtilManager
    {
        public:
        static MQTTUtils* mqttUtils;
        static TimeUtils* timeUtils;
        static PinUtils* pinUtils; 

    };

    MQTTUtils* UtilManager::mqttUtils = new MQTTUtils();
    TimeUtils* UtilManager::timeUtils = new TimeUtils();
    PinUtils* UtilManager::pinUtils = new PinUtils();

    #endif