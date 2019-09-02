/**
 * @file LaunchState.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief The launchState header file
 * @version 0.1
 * @date 2019-09-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LAUNCHSTATE_H 
#define LAUNCHSTATE_H
#include "State.cpp"

class LaunchState: public State {
    public:
        LaunchState();
        std::string name();
        int keyPressed(int number, int timeInState);
        State *next();     
        std::string displayInfo(time_t currentTime, time_t startOfProgram, time_t timeOfLastStateSwitch, int num);

    private:
};

#endif

