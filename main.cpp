/**
 * @file main.cpp
 * @author your name https://github.com/ryan-keswick
 * @brief Main body of the program that handles the states and runs it
 * @version 0.1
 * @date 2019-09-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "SafeState.hpp"
#include "LaunchState.hpp"
#include "BrakeState.hpp"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include "time.h"
#include <thread>

State *state;                       // The current State
void waitKeyForPress();             
void next();
time_t startOfProgram;              // The time when the program starts
time_t currentTime;                 // The current time of the program
time_t timeOfLastStateSwitch;       // The time when the state last changed
void createTimer();
void handleKeyPress(int number);
void printError();
void StartOutput();
std::string displayInfo();
int num = 0;                        // The keyboard number pressed
void checkIfLaunchShouldStop();

int main(void) {
    // Starts the program off in the safe state
    SafeState *safe = new SafeState();
    state = safe;  
    
    // Creates a new thread so the output can be continuously printed
    // A thread allows two thread running access the same memoryj
    std::thread PrintingThread(StartOutput);

    // Begins looking for keyboard inputs to be pressed
    waitKeyForPress();

    return 0;
}

/**
 * @brief A function that continously waits and reads in a int.
 * After an int is entered it runs again
 * 
 */
void waitKeyForPress() {
    int number = 0;
    scanf("%d", &number);
    handleKeyPress(number);
    waitKeyForPress();
}

/**
 * @brief basic error checking on the number entered and decides whever to switch state
 * 
 * @param number The number to be checked
 */
void handleKeyPress(int number) {
    // Makes sure number isn't out of range
    if (number < 0 || 100 < number) {
        printError();
        return;
    // If the keyPressed() fails then it prints an error message
    } else if(state->keyPressed(number, difftime(currentTime, timeOfLastStateSwitch)) == 1) {
        next();
    } else if (state->keyPressed(number, difftime(currentTime, timeOfLastStateSwitch)) != 2){
        printError();
    }
    // If the state is the launch state, it also records that number so it can be used later
    // A better implementation would be to put this into the launchState
    if (state->name().compare("LAUNCH") == 0) num = number;
}

/**
 * @brief Changes to the next state
 * 
 */
void next() {
    state = state->next();
    // Records the time when the program changed
    time(&timeOfLastStateSwitch);
}

/**
 * @brief Printing error message, could be expanded to help debugging
 * 
 */
void printError() {
    printf("Error\n");
}

/**
 * @brief One of the threads continues here and repeats printing out the 
 * status of the pod every one second
 * 
 */
void StartOutput() {
    // Records now as the start of the program and also sets the first state change time
    time(&startOfProgram);
    time(&timeOfLastStateSwitch);

    int i = 0;
    while(i<19) { // An infinite Loop to show the time
        time(&currentTime);
       
        checkIfLaunchShouldStop();
        std::cout << state->displayInfo(currentTime, startOfProgram, timeOfLastStateSwitch, num);
        sleep(1); 
       // DEBUGING i++;
    }
}

/**
 * @brief Checks if its is in the launch state and if its been in it
 * for more than 15 seconds. If it has then it changes to the next state.
 * 
 */
void checkIfLaunchShouldStop() {
    // Checks if it has been in launch for more than 15 seconds, if it has 
    // Changes states, this really should be in the LaunchState for better code
    if (state->name().compare("LAUNCH") == 0  && difftime(currentTime, timeOfLastStateSwitch) > 14)
        next();
}