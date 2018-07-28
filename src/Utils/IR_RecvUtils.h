#ifndef IR_RecvUtils_h
    #define IR_RecvUtils_h

    #include <IRremoteESP8266.h>
    #include <IRsend.h>
    #include <IRrecv.h>
    #include <IRutils.h>

    int RECV_PIN = D1;
    IRrecv irrecv(RECV_PIN);
    decode_results results;
//TODO : Clean up this class variables. desc below//
// I want these 3 inside of the class. Could not make it work today (11/28). //


    class IR_RecvUtils
    {
        static constexpr long long IR_Values[10]= {123,12583021,12583022,12583023,12583024};
        static const int IRValuesCount = 5;

        public:
            void setupIR_recv()
            {
                irrecv.enableIRIn(); // Start the receiver
            }

            int getDecode()
            {
                if (irrecv.decode(&results)) 
                {
                    Serial.println("Recvd result");
                    irrecv.resume(); // Receive the next value
                    //String msg="Receive value: ";
                    // msg= msg+ results.value;
                    char message[58];
                    message[0] = '\0';
                    int messageLength = 1;
                    long long val = results.value;
                    int i=0;
                    while(val != 0)
                    {
                        message[messageLength] = '\0'; //always the last char
                        message[i] = '0' + val%10;
                        val /= 10;
                        i++;
                        messageLength++;
                    }
                    Serial.println(message);
                    i = 0;
                    for(i=0;i<IRValuesCount;i++)
                    {
                        if(results.value == IR_Values[i])
                        {
                            return i+1;
                        }
                    }
                    return 0;
                }
                return -1;
            }
    };

#endif