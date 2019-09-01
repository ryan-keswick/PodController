/**
 * @file State.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief 
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */
#ifndef STATE_H 
#define STATE_H 
#include <iostream>


/** Parent Class for all the states,
 *  This is a very good thing to add incase if you
 *  wanted to add any behaviour to all the states easily
 * 
**/  
class State {
    public:
        char name[10] = "Safe";
    private:
};


#endif 