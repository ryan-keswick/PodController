#include "Output.hpp"

Output::Output(PodController *podPointer) {
    this->pod = podPointer;
    printf("sadsadasdADSD\n");
}

void Output::operator()() {
    printf("IM OPERATING WNHY");
}

void Output::run() {
    time(&this->pod->startOfProgram);
    time(&this->pod->timeOfLastStateSwitch);

    int i = 0;
    while(i<10) { // An infinite Loop to show the time
        time(&this->pod->currentTime);
        std::cout << displayInfo();
        sleep(1); 
        i++;
    }
}

std::string Output::displayInfo() {
    std::string currState (this->pod->state->name().c_str());
    std::string timeSinceStart (std::to_string(difftime(this->pod->currentTime, this->pod->startOfProgram)));
    std::string timeInCurrState(std::to_string(difftime(this->pod->currentTime, this->pod->timeOfLastStateSwitch)));

    return currState + " " + timeSinceStart + " " + timeInCurrState + "\n";
}