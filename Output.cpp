#include "Output.hpp"
#include "PodController.hpp"

Output::Output(PodController* Pod) {
    printf("Observer  created\n");
    time(&this->startOfProgram);
    time(&this->timeOfLastStateSwitch);
    time(&this->currentTime);
    this->pod = Pod;

    int i = 0;
    while(i<1) { // An infinite Loop to show the time
        displayInfo();
        sleep(1); 
    }

}

void Output::displayInfo() {
    printf("%s ", this->pod->state->name);
    printf("%.f ", difftime(this->currentTime, this->startOfProgram));
    printf("%.f\n", difftime(this->currentTime, this->timeOfLastStateSwitch));
}