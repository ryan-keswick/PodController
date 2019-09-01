#include "Output.hpp"
#include "PodController.hpp"

Output::Output(PodController* Pod) {
    printf("Observer  created\n");
    time(&this->startOfProgram);
    time(&this->timeOfLastStateSwitch);
    this->pod = Pod;

    int i = 0;
    while(i<10) { // An infinite Loop to show the time
        time(&this->currentTime);
        displayInfo();
        sleep(1); 
        i++;
    }

}

void Output::displayInfo() {
    printf("%s ", this->pod->state->name);
    printf("%.f ", difftime(this->currentTime, this->startOfProgram));
    printf("%.f\n", difftime(this->currentTime, this->timeOfLastStateSwitch));
}