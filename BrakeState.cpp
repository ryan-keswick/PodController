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


