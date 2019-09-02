/**
 * @file State.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief 
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */

/** Abstract Class for all the states,
 *  This is a very good thing to add incase if you
 *  wanted to add any behaviour to all the states easily
 * 
**/  
#include <stdio.h>
#ifndef STATE_H 
#define STATE_H 
#include <string>

class State {
    public:
        virtual std::string name() = 0;
        virtual bool keyPressed(int number) = 0;
        virtual State *next() = 0;
    private:
};

#endif
