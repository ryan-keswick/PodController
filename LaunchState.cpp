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
#include "BrakeState.hpp"

LaunchState::LaunchState() {
    //printf("Launch\n");
}

int LaunchState::keyPressed(int number) {
    if (number == 2) {printf("Emergency\n"); return 1;}
    return 2;
}

State *LaunchState::next() {
    BrakeState *brake = new BrakeState();
    return brake;  
}

std::string LaunchState::name() {
    return "LAUNCH";
}
