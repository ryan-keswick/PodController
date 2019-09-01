
PodController: BrakeState.o LaunchState.o main.o Observer.o PodController.o SafeState.o 
	g++ BrakeState.o LaunchState.o main.o Observer.o PodController.o SafeState.o -o PodController 

BrakeState.o: BrakeState.cpp	
	g++ -c BrakeState.cpp

LaunchState.o: LaunchState.cpp
	g++ -c LaunchState.cpp

main.o: main.cpp
	g++ -c main.cpp

Observer.o: Observer.cpp
	g++ -c Observer.cpp

PodController.o: PodController.cpp
	g++ -c PodController.cpp

SafeState.o: SafeState.cpp
	g++ -c SafeState.cpp


clean: 
	rm *.o PodController 