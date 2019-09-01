/**
 * @file PodController.cpp
 * @author your name https://github.com/ryan-keswick
 * @brief 
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */
#include "SafeState.hpp"
#include "LaunchState.hpp"
#include "BrakeState.hpp"
#include "Observer.hpp"
#include <stdio.h>
#include <unistd.h>


class PodController {
    State state;
    Observer observer;

    public:
        PodController() {
            SafeState safe;
            state = new SafeState();
            createTimer();
        }
    private:
        /**
         * Creates a timer object that can observe the pod whenever
         * The child operates the timer object indefinately
         */
        void createTimer() {
            pid_t  pid = fork();
            if (pid == 0) {
                // Child Process operates the Timer that prints the state
                // every 1 second and the info
                time = new Timer(this); 
            } else if (pid  > 0) {
                // Parent Process Just Continues
            } else {
                printf("FORK FAILED, most likely ran out of memory\n");
            }
        }

};

int main(void) {

    return 0;
}