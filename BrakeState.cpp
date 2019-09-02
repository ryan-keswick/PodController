/**
 * @file BrakeState.cpp
 * @author your name https://github.com/ryan-keswick 
 * @brief The brakeState with its properties
 * @version 0.1
 * @date 2019-09-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "BrakeState.hpp"
#include "SafeState.hpp"


BrakeState::BrakeState() {
//    printf("Braking");
}

int BrakeState::keyPressed(int number, int timeInState) {
    if (number == 99 && timeInState > 4) {
        printf("Brooklyn\n");
        return 1;
    }
    return 0;    
}

State *BrakeState::next() {
    SafeState *safe = new SafeState();
    return safe; 
}

std::string BrakeState::name() {
    return "BRAKE";
}

std::string BrakeState::displayInfo(time_t currentTime, time_t startOfProgram, time_t timeOfLastStateSwitch, int num) {
    // Creates the right strings to be manipulated
    std::string currState (name().c_str());
    std::string timeSinceStart (std::to_string(difftime(currentTime, startOfProgram)));
    std::string timeInCurrState(std::to_string(difftime(currentTime, timeOfLastStateSwitch)));
    return currState + " " + timeSinceStart + " " + timeInCurrState + "\n";
}