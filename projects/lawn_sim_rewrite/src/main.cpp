#include <iostream>

#include "Simulation.h"

int main()
{
	//create simulation
	Simulation *sim = new Simulation();
	
	//initialize and run simulation
	if (sim->init() != 0)
		printf("Error in simulation initiation");
	if (sim->run() != 0)
		printf("Error in simulation run() function");


	int k;
	std::cin >> k;
	return 0;
}