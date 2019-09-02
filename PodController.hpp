#ifndef PODCONTROLLER_H 
#define PODCONTROLLER_H
#include "SafeState.hpp"
#include "LaunchState.hpp"
#include "BrakeState.hpp"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <boost/interprocess/shared_memory_object.hpp>
#include "time.h"

#define READ_FD     0
#define WRITE_FD    1

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
        int fd[2];
};

#endif