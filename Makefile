
PodController: BrakeState.o LaunchState.o main.o PodController.o SafeState.o State.o
	g++ -std=c++11 -pthread BrakeState.o LaunchState.o main.o  PodController.o SafeState.o State.o -o PodController 

BrakeState.o: BrakeState.cpp	
	g++ --std=c++11 -pthread -c BrakeState.cpp

LaunchState.o: LaunchState.cpp
	g++ --std=c++11 -pthread -c LaunchState.cpp

main.o: main.cpp
	g++ --std=c++11 -pthread -c main.cpp

PodController.o: PodController.cpp
	g++ --std=c++11 -pthread -c PodController.cpp

SafeState.o: SafeState.cpp
	g++ --std=c++11 -pthread -c SafeState.cpp

State.o: State.cpp
	g++ --std=c++11 -pthread -c State.cpp


clean: 
	rm *.o PodController 