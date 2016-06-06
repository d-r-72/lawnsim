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
	m_currentDay = 1;
	m_currentWeek = 1;

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
		if(m_currentWeek != 7)
			simulateWeek();
		
		printStats();
		
		//updates
		if (cutGrass())
			m_player->update(*m_map);


	}
	//delete pointers
	cleanUp();
	return 0;
}

void Simulation::simulateWeek()
{
	m_map->grow(0.62f);

	m_currentWeek++;
}

void Simulation::cleanUp()
{
	delete m_map;
	delete m_player;
}

bool Simulation::cutGrass()
{
	bool result = false;

	printf("The average tile of grass height is: %f\n", m_map->getAvgTileHeight());
	printf("Would you like to mow? (y,n)");
	char answer;
	answer = _getch();
	if (answer == 'y')
		result = true;
	if (answer == 'Y')
		result = true;

	printf("\n");
	return result;
}

void Simulation::printStats()
{
	printf("Current day: %d\n", m_currentDay);
	printf("Current week: %d\n", m_currentWeek);
	printf("Total grass height: %f\n", m_map->getTotalHeight());
	printf("Player points: %f\n", m_player->getPoints());
	printf("Player name: %s\n", m_player->getName().c_str());
	printf("Player symbol: %c\n", m_player->getSymbol());
}
