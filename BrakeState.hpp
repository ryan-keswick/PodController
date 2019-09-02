#ifndef BRAKESTATE_H 
#define BRAKESTATE_H
#include "State.cpp"

class BrakeState: public State {
    public:
        BrakeState();
        std::string name();
        int keyPressed(int number, int timeInState);
        State *next();
    private:
};


#endif


