#ifndef PODCONTROLLER_H 
#define PODCONTROLLER_H
#include "SafeState.hpp"
#include "LaunchState.hpp"
#include "BrakeState.hpp"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "time.h"

class PodController {
    public:
        PodController();
        State *state;
        void waitKeyForPress();
    private:
        void Output();
        void createTimer();
        void handleKeyPress(int number);
        void displayInfo();      
        void printError();
        time_t startOfProgram;
        time_t currentTime;
        time_t timeOfLastStateSwitch;
};

#endif