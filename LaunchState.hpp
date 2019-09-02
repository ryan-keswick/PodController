#ifndef LAUNCHSTATE_H 
#define LAUNCHSTATE_H
#include "State.cpp"


class LaunchState: public State {
    public:
        LaunchState();
        std::string name();
        int keyPressed(int number);
        State *next();     
    private:
};

#endif

