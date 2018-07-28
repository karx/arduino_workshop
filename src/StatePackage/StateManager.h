#ifndef StateManager_h
    #define StateManager_h

    #include "State.h"

    class StateManager
    {
        State stateChain[5] = {
            State(0,1,true),
            State(2,"PehlaMQ"),
            State(1,4),
            State(2,"Dusra"),
            State(0,1,false)
        };

        public:
        void runStateChain()
        {
            stateChain[State::currentStateIndex].executeState();
        }

    };

    #endif