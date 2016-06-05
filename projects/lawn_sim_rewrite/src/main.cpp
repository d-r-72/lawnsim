#include <iostream>

#include "Simulation.h"

int main()
{
	Simulation *sim = new Simulation();
	if (sim->init() != 0)
		printf("Error in simulation initiation");
	if (sim->run() != 0)
		printf("Error in simulation run() function");


	int k;
	std::cin >> k;
	return 0;
}