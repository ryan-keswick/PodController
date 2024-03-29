/**
 * @file SafeState.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief The safeState Header file
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */
#ifndef SAFESTATE_H
#define SAFESTATE_H
#include "State.cpp"

class SafeState: public State {
    public:
        SafeState();
        std::string name();
        int keyPressed(int number, int timeInState);
        State *next();
        std::string displayInfo(time_t currentTime, time_t startOfProgram, time_t timeOfLastStateSwitch, int num);
    private:

};


#endif
