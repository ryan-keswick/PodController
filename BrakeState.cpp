#include "BrakeState.hpp"
#include "SafeState.hpp"



BrakeState::BrakeState() {
    printf("Braking");
}

bool BrakeState::keyPressed(int number) {
    return false;    
}

State *BrakeState::next() {
    SafeState *safe = new SafeState();
    return safe; 
}

std::string BrakeState::name() {
    return "BRAKE";
}


