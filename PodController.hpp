#ifndef PODCONTROLLER_H 
#define PODCONTROLLER_H
#include "SafeState.hpp"
#include "LaunchState.hpp"
#include "BrakeState.hpp"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
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
        std::string displayInfo();      
        void writePipe();
        void printError();
        time_t startOfProgram;
        time_t currentTime;
        time_t timeOfLastStateSwitch;
};

#endif