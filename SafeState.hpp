/**
 * @file SafeState.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief 
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
    private:

};


#endif
