/**
 * @file Observer.hpp
 * @author your name https://github.com/ryan-keswick
 * @brief 
 * @version 0.1
 * @date 2019-09-01
 * 
 * 
 */
#ifndef OBSERVER_H 
#define OBSERVER_H 
#include "State.hpp"

class Timer: {
    PodController pod;
    public:
        Timer(PodController PodToBeObserved) {
            pod = PodToBeObserved;
        }
    private:
};


#endif
