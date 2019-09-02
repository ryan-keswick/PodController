/**
 * @file BrakeState.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief The Header file for the brakeState
 * @version 0.1
 * @date 2019-09-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BRAKESTATE_H 
#define BRAKESTATE_H
#include "State.cpp"

class BrakeState: public State {
    public:
        BrakeState();
        std::string name();
        int keyPressed(int number, int timeInState);
        State *next();
    private:
};


#endif


