#ifndef PayloadUtils_h
    #define PayloadUtils_h

    #include <Arduino.h>
    
class PayloadUtils
{
public:
    static void parseAndExecutePayload(byte* payload,int len);
    
    static int getValuefromByteString(byte *payload,int len);
};
#endif


//type:2 bytes 0,1
//Pin: 2 bytes 2,3
//Value: 4 bytes, 4,5,6,7

//Total 8 bytes