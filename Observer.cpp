#include "Observer.hpp"
#include "PodController.hpp"

Observer::Observer(PodController *PodController) {
    printf("Observer  created\n");
    time(&this->startOfProgram);
    time(&this->timeOfLastStateSwitch);
    time(&this->currentTime);
    this->pod = *PodController;

    int i = 0;
    while(i<1) { // An infinite Loop to show the time
        displayInfo();
        sleep(1); 
    }

}

void Observer::displayInfo() {
    printf("%s ", this->pod.state->name);
    printf("%.f ", difftime(this->currentTime, this->startOfProgram));
    printf("%.f\n", difftime(this->currentTime, this->timeOfLastStateSwitch));
}