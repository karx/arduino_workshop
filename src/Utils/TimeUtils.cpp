#include "TimeUtils.h"
#include <Arduino.h>

TimeUtils::TimeUtils()
{
    previousMillis = millis();
    timeOutSet = false;
    timeOutStartMillis = 0;
}
    
bool TimeUtils :: every5sec()
{
    return everyXsec(5);
}

bool TimeUtils :: everyXsec(long interval)
{
    return everyXMillisec(interval*1000);
}

bool TimeUtils::everyXMillisec(long interval)
{
    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis > (interval))
    {
    // save the last time you blinked the LED 
        previousMillis = currentMillis;     
        return true;
    }
    return false;
}

bool TimeUtils :: timeoutXsec(int seconds)
{
    if(timeOutSet)
    {
        unsigned long currentMillis = millis();

        if(currentMillis - timeOutStartMillis > (seconds*1000))
        {
            timeOutSet = false;
            Serial.print("Timeout ENDED after - ");
            Serial.println(seconds);
    
            return true;
        }
        return false;
    }
    else
    {
        timeOutStartMillis=millis();
        timeOutSet=true;
        Serial.print("Timeout Start is set to ");
        Serial.println(timeOutStartMillis);
        return false;
    }
}
