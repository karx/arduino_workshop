#ifndef WifiUtils_h
    #define WifiUtils_h

    #include <ESP8266WiFi.h>

    class WifiUtils
    {
        
        static constexpr  char* ssid = "kaaro-redmi";
        static constexpr  char* password = "123456789";
        // static constexpr  char* password = "9810110717";
        
        public:
            static void setup_wifi();

    };

#endif