#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <string>

#include "Player.h"
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

	bool m_done;

	Player *m_player;
	Map *m_map;
};

#endif //SIMULATION_H
