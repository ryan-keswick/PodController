/**
 * @file State.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief      Parent State where all other states inherit from 
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
/**
 * @brief This the state with some abstract functions to be implement by its child states
 * 
 */
class State {
    public:
        virtual std::string name() = 0;
        virtual int keyPressed(int number, int timeInState) = 0;
        virtual State *next() = 0;
        
        std::string displayInfo(time_t currentTime, time_t startOfProgram, time_t timeOfLastStateSwitch, int num) {
            // Creates the right strings to be manipulated
            std::string currState (name().c_str());
            std::string timeSinceStart (std::to_string(difftime(currentTime, startOfProgram)));
            std::string timeInCurrState(std::to_string(difftime(currentTime, timeOfLastStateSwitch)));
            return currState + " " + timeSinceStart + " " + timeInCurrState + "\n";
        }
    private:
};

#endif