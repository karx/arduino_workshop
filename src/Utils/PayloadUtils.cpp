#include "PayloadUtils.h"

void PayloadUtils::parseAndExecutePayload(byte* payload,int len)
{
    int type = getValuefromByteString(payload,2);
    int pin = getValuefromByteString(payload + 2,2);
    int value = getValuefromByteString(payload+ 4,4);

    switch(type)
    {
    case 0://boolean
            digitalWrite(pin,value ==0 ? LOW : HIGH);
            Serial.println("DigitalWrite Completed");
            break;
    default: Serial.println("Type undef");            
    }
}

int PayloadUtils::getValuefromByteString(byte *payload,int len)
{
    int i=0;
    int result = 0;
    for(i = 0;i<len;i++)
    {
        result *= 10;
        result += (char)payload[i]-'0';
    }
    Serial.print("Result Returning = ");
    Serial.println(result);
    return result;
}