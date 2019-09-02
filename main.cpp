#include "PodController.hpp"
#include <iostream>

State *state;
void waitKeyForPress();
time_t startOfProgram;
time_t currentTime;
time_t timeOfLastStateSwitch;   
void createTimer();
void handleKeyPress(int number);
void printError();
void StartOutput();
std::string displayInfo();

int main(void) {
    SafeState *safe = new SafeState();
    printf("%p\n", safe);
    printf("%s\n", safe->name().c_str());
    state = safe;  
    std::thread thread(StartOutput);
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
    } else if(state->keyPressed(number)) {
        state = state->next();
        time(&timeOfLastStateSwitch);
    } else {
        printError();
    }
}

void printError() {
    printf("Error");
}

void StartOutput() {
    time(&startOfProgram);
    time(&timeOfLastStateSwitch);

    int i = 0;
    while(i<10) { // An infinite Loop to show the time
        time(&currentTime);
        std::cout << displayInfo();
        sleep(1); 
        i++;
    }
}

std::string displayInfo() {
    std::string currState (state->name().c_str());
    std::string timeSinceStart (std::to_string(difftime(currentTime, startOfProgram)));
    std::string timeInCurrState(std::to_string(difftime(currentTime, timeOfLastStateSwitch)));

    return currState + " " + timeSinceStart + " " + timeInCurrState + "\n";
}