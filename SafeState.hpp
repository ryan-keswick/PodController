/**
 * @file SafeState.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief 
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */
#include "LaunchState.hpp"
#ifndef SAFESTATE_H
#define SAFESTATE_H
#include "State.hpp"

class SafeState: public State {
    public:
        SafeState();
        char name[5] = "Safe";
        bool keyPressed(int number);
        State *next();
    private:

};


#endif
