#ifndef LAUNCHSTATE_H 
#define LAUNCHSTATE_H
#include "State.hpp"

class LaunchState: public State {
    public:
        LaunchState();
        char name[8] = "Launch";
    private:
};

#endif

