/**
 * @file Observer.hpp
 * @author your name https://github.com/ryan-keswick
 * @brief 
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */
#ifndef OBSERVER_H 
#define OBSERVER_H 
#include "State.hpp"
#include "PodController.hpp"
#include "time.h"

class Output {
    public:
        Output(PodController *Pod);
        void displayInfo();
    private:
        PodController *pod;
        time_t startOfProgram;
        time_t currentTime;
        time_t timeOfLastStateSwitch;
};

#endif
