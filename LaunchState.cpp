#include "LaunchState.hpp"

LaunchState::LaunchState() {
    printf("In the launch");
}

bool LaunchState::keyPressed(int number) {

}

State *LaunchState::next() {

}

std::string LaunchState::name() {
    return "Launch";
}

