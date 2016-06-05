#include "Simulation.h"

Simulation::Simulation()
{
}


Simulation::~Simulation()
{
}

int Simulation::init()
{
	_done = false;
	s_map = new Map();

	return 0;
}

int Simulation::run()
{
	while (!_done)
	{

	}
	cleanUp();
	return 0;
}

void Simulation::cleanUp()
{
	delete s_map;
}
