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
	m_map = new Map();
	
	m_player = new Player(0, 0, 0.0f, '@', "David");

	m_map->init();
	m_player->init(*m_map);

	return 0;
}

int Simulation::run()
{
	while (!m_done)
	{
		m_map->update();
		m_player->update(*m_map);
		printf("%s",std::string(100, '\n').c_str());
	}
	cleanUp();
	return 0;
}

void Simulation::cleanUp()
{
	delete m_map;
	delete m_player;
}
