#ifndef PinUtils_h
    #define PinUtils_h

    #include <Arduino.h>

    class PinUtils
    {
        public:
        void setPinState(int pin, bool state);
        bool getPinState(int pin);
        bool togglePinState(int pin);    //return new state of the pin
    };

#endif