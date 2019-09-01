#ifndef PODCONTROLLER_H 
#define PODCONTROLLER_H
#include "SafeState.hpp"
#include "LaunchState.hpp"
#include "BrakeState.hpp"
#include "Output.hpp"
#include <stdio.h>
#include <unistd.h>

class PodController {
    

    public:
        PodController();
        State *state;
    private:
        void createTimer();
};

#endif