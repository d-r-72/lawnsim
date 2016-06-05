#pragma once
#include <iostream>
#include <string>

#include "Map.h"

class Simulation
{
public:
	Simulation();
	~Simulation();

	int init();
	int run();

	void cleanUp();

private:

	bool _done;
	Map *s_map;
};
