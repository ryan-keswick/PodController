#ifndef BRAKESTATE_H 
#define BRAKESTATE_H
#include "State.cpp"

class BrakeState: public State {
    public:
        BrakeState();
        std::string name();
        int keyPressed(int number);
        State *next();
    private:
};


#endif


