#ifndef TimeUtils_h
    #define TimeUtils_h
    
    class TimeUtils
    {
        bool timeOutSet;
        long timeOutStartMillis;
        long previousMillis; 
        
        public:
            TimeUtils();
            bool every5sec();
            bool everyXsec(long interval);
            bool timeoutXsec(int seconds);
            bool everyXMillisec(long interval);
            
    };

#endif