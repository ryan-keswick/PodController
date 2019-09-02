/**
 * @file SafeState.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief The safeState file with the states properties'
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */
#include "SafeState.hpp"
#include "LaunchState.hpp"

SafeState::SafeState() {
    //printf("In Safe State\n");
}

int SafeState::keyPressed(int number, int timeInState) {
    if (number == 1) {return true;}
    else {return false;}
}

State *SafeState::next() {
    LaunchState *launch  = new LaunchState();
    return launch;  
}

std::string SafeState::name() {
    return "Safe";
}
