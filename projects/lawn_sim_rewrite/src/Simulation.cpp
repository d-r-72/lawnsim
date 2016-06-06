#include "Simulation.h"

Simulation::Simulation()
{
}


Simulation::~Simulation()
{
}

int Simulation::init()
{
	m_done = false;
	//setup map and player
	m_map = new Map();
	m_player = new Player(0, 0, 0.0f, '@', "David");

	//initialize map and player
	m_map->init();
	m_player->init(*m_map, 0, 0);

	return 0;
}

int Simulation::run()
{
	//main loop
	while (!m_done)
	{
		//updates	
		m_map->update();
		m_player->update(*m_map);

		//'clear' the map
		printf("%s",std::string(100, '\n').c_str());
	}
	//delete pointers
	cleanUp();
	return 0;
}

void Simulation::cleanUp()
{
	delete m_map;
	delete m_player;
}
