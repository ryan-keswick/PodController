/**
 * @file PodController.cpp
 * @author your name https://github.com/ryan-keswick
 * @brief 
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */
#include "PodController.hpp"
   
PodController::PodController() {
    SafeState *safe = new SafeState();
    printf("%p\n", safe);
    printf("%s\n", safe->name().c_str());
    state = safe;  
    createTimer();
    printf("new pod\n");
    waitKeyForPress();
}

void PodController::createTimer() {
    pid_t  pid = fork();
    if (pid == 0) {
        // Child Process operates the Timer that prints the state
        // every 1 second and the info
        Output();
    } else if (pid  > 0) {
        // Parent Process Just Continues
    } else {
        printf("FORK FAILED, most likely ran out of memory\n");
    }
}

void PodController::waitKeyForPress() {
    int number = 0;
    scanf("%d", &number);
    handleKeyPress(number);
    waitKeyForPress();
}

void PodController::handleKeyPress(int number) {
    if (number < 0 || 100 < number) printError();
    // If the keyPressed() fails then it prints an error message
    if(state->keyPressed(number)) {
        state = state->next();
    } else {
        printError();
    }
}

void PodController::printError() {
    printf("Error");
}

void PodController::Output() {
    time(&this->startOfProgram);
    time(&this->timeOfLastStateSwitch);

    int i = 0;
    while(i<10) { // An infinite Loop to show the time
        time(&this->currentTime);
        std::cout << displayInfo();
        sleep(1); 
        i++;
    }
}

std::string PodController::displayInfo() {
    std::string currState (state->name().c_str());
    std::string timeSinceStart (std::to_string(difftime(this->currentTime, this->startOfProgram)));
    std::string timeInCurrState(std::to_string(difftime(this->currentTime, this->timeOfLastStateSwitch)));

    return currState + " " + timeSinceStart + " " + timeInCurrState + "\n";
}