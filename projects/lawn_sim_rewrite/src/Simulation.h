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


private:
	void simulateWeek();
	void cleanUp();
	bool cutGrass();
	void printStats();

	bool m_done;

	int m_currentWeek;
	int m_currentDay;

	Player *m_player;
	Map *m_map;
};

#endif //SIMULATION_H
