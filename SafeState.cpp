/**
 * @file SafeState.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief 
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */
#include "SafeState.hpp"
#include "LaunchState.hpp"

SafeState::SafeState() {
    printf("In Safe State\n");
}

bool SafeState::keyPressed(int number) {
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
