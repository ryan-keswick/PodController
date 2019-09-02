#include "BrakeState.hpp"
#include "SafeState.hpp"



BrakeState::BrakeState() {
//    printf("Braking");
}

int BrakeState::keyPressed(int number) {
    return 0;    
}

State *BrakeState::next() {
    SafeState *safe = new SafeState();
    return safe; 
}

std::string BrakeState::name() {
    return "BRAKE";
}


