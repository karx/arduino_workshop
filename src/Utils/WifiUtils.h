#ifndef WifiUtils_h
    #define WifiUtils_h

    #include <ESP8266WiFi.h>

    class WifiUtils
    {
        
        static constexpr  char* ssid = "LPS Global Pool Wifi";
        static constexpr  char* password = "lps@12345";
        // static constexpr  char* password = "9810110717";
        
        public:
            static void setup_wifi();

    };

#endif