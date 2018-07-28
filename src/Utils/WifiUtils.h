#ifndef WifiUtils_h
    #define WifiUtils_h

    #include <ESP8266WiFi.h>

    class WifiUtils
    {
        
        static constexpr  char* ssid = "Mridula";
        static constexpr  char* password = "20081957";
        // static constexpr  char* password = "9810110717";
        
        public:
            static void setup_wifi();

    };

#endif