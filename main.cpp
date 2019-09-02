#include "SafeState.hpp"
#include "LaunchState.hpp"
#include "BrakeState.hpp"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include "time.h"
#include <thread>

State *state;
void waitKeyForPress();
void next();
time_t startOfProgram;
time_t currentTime;
time_t timeOfLastStateSwitch;   
void createTimer();
void handleKeyPress(int number);
void printError();
void StartOutput();
std::string displayInfo();
int num = 0;

int main(void) {
    SafeState *safe = new SafeState();
    printf("%p\n", safe);
    printf("%s\n", safe->name().c_str());
    state = safe;  
    std::thread PrintingThread(StartOutput);
    printf("Parent Done Creating Timer\n");
    waitKeyForPress();


    return 0;
}

void waitKeyForPress() {
    int number = 0;
    scanf("%d", &number);
    handleKeyPress(number);
    waitKeyForPress();
}

void handleKeyPress(int number) {
    if (number < 0 || 100 < number) {
        printError();
        return;
    // If the keyPressed() fails then it prints an error message
    } else if(state->keyPressed(number, difftime(currentTime, timeOfLastStateSwitch)) == 1) {
        next();
    } else if (state->keyPressed(number, difftime(currentTime, timeOfLastStateSwitch)) != 2){
        printError();
    }
    if (state->name().compare("LAUNCH") == 0) num = number;
}

void next() {
    state = state->next();
    time(&timeOfLastStateSwitch);
}
void printError() {
    printf("Error\n");
}

void StartOutput() {
    time(&startOfProgram);
    time(&timeOfLastStateSwitch);

    int i = 0;
    while(i<19) { // An infinite Loop to show the time
        time(&currentTime);
        std::cout << displayInfo();
        sleep(1); 
       // DEBUGING i++;
    }
}

std::string displayInfo() {
    std::string currState (state->name().c_str());
    std::string timeSinceStart (std::to_string(difftime(currentTime, startOfProgram)));
    std::string timeInCurrState(std::to_string(difftime(currentTime, timeOfLastStateSwitch)));


    if (state->name().compare("LAUNCH") == 0  && difftime(currentTime, timeOfLastStateSwitch) > 14) {
        next();
    } else if (state->name().compare("LAUNCH") == 0) {
        int speedMultiplier = num * difftime(currentTime, timeOfLastStateSwitch);
        return currState + " " + timeSinceStart + " " + timeInCurrState + " " + std::to_string(speedMultiplier) + "\n";
    } 
    return currState + " " + timeSinceStart + " " + timeInCurrState + "\n";
}