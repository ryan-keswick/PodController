#ifndef OUTPUT_H 
#define OUTPUT_H 
#include "PodController.hpp"

class Output {
    public:
        Output(PodController *podPointer);
    private:
        void run();
        PodController *pod;
        std::string displayInfo();
        void operator()();

};


#endif