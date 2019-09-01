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
    state = safe;  
    createTimer();
    printf("new pod\n");
}

void PodController::createTimer() {
    pid_t  pid = fork();
    if (pid == 0) {
        // Child Process operates the Timer that prints the state
        // every 1 second and the info
        Observer *observer = new Observer(this); 
    } else if (pid  > 0) {
        // Parent Process Just Continues
    } else {
        printf("FORK FAILED, most likely ran out of memory\n");
    }
}