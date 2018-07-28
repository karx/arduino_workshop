#include "PinUtils.h"

void PinUtils :: setPinState(int pin, bool state)
{
    digitalWrite(pin,state? HIGH : LOW);
}

bool PinUtils :: getPinState(int pin)
{
    return (digitalRead(pin) == HIGH ? true : false);
}

bool PinUtils :: togglePinState(int pin)    //return new state of the pin
{
    bool currentState = getPinState(pin);
    setPinState(pin,!currentState);
    return !currentState;
}
