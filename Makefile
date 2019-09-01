
PodController: BrakeState.o LaunchState.o main.o Output.o PodController.o SafeState.o State.o
	g++ BrakeState.o LaunchState.o main.o Output.o PodController.o SafeState.o State.o -o PodController 

BrakeState.o: BrakeState.cpp	
	g++ -c BrakeState.cpp

LaunchState.o: LaunchState.cpp
	g++ -c LaunchState.cpp

main.o: main.cpp
	g++ -c main.cpp

Observer.o: Output.cpp
	g++ -c Output.cpp

PodController.o: PodController.cpp
	g++ -c PodController.cpp

SafeState.o: SafeState.cpp
	g++ -c SafeState.cpp

State.o: State.cpp
	g++ -c State.cpp


clean: 
	rm *.o PodController 