#ifndef PODCONTROLLER_H 
#define PODCONTROLLER_H
#include "SafeState.hpp"
#include "LaunchState.hpp"
#include "BrakeState.hpp"
#include <stdio.h>
#include <unistd.h>

class PodController {
    public:
        PodController();
        State *state;
        void waitKeyForPress();
    private:
        void createTimer();
        void handleKeyPress(int number);
        void printError();
};

#endif