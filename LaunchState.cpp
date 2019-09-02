/**
 * @file SafeState.hpp
 * @author your name https://github.com/ryan-keswick 
 * @brief The LaunchState with its own properties
 * @version 0.1
 * @date 2019-09-01
 * 
 */
#include "LaunchState.hpp"
#include "BrakeState.hpp"

LaunchState::LaunchState() {
    //printf("Launch\n");
}

int LaunchState::keyPressed(int number, int timeInState) {
    if (number == 2) {printf("Emergency\n"); return 1;}
    else if (number == 1) return 0;
    return 2;
}

State *LaunchState::next() {
    BrakeState *brake = new BrakeState();
    return brake;  
}

std::string LaunchState::name() {
    return "LAUNCH";
}

std::string LaunchState::displayInfo(time_t currentTime, time_t startOfProgram, time_t timeOfLastStateSwitch, int num) {
    // Creates the right strings to be manipulated
    std::string currState (name().c_str());
    std::string timeSinceStart (std::to_string(difftime(currentTime, startOfProgram)));
    std::string timeInCurrState(std::to_string(difftime(currentTime, timeOfLastStateSwitch)));

    // Multiplies the num by the time spent in the launch state,
    if (num != 1 && num != 2) {
        int speedMultiplier = num * difftime(currentTime, timeOfLastStateSwitch);
        return currState + " " + timeSinceStart + " " + timeInCurrState + " " + std::to_string(speedMultiplier) + "\n";
    }
    return currState + " " + timeSinceStart + " " + timeInCurrState + "\n";
}
 