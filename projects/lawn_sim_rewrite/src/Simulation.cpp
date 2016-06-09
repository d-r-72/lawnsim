#include "Simulation.h"

Simulation::Simulation()
{
	printf("Weather stats? ");
	char in = _getch();
	if (in == 'y')
		m_weatherStats = true;
	else
		m_weatherStats = false;
}


Simulation::~Simulation()
{
}

int Simulation::init()
{
	m_done = false;
	m_currentDay = 1;
	m_currentWeek = 1;

	//initialize pointers
	m_map = new Map();
	m_player = new Player(0, 0, 0.0f, '@', "David");
	m_weather = new Weather();

	//initialize map and player
	m_map->init();
	m_player->init(*m_map, 0, 0);

	return 0;
}

void Simulation::simulateDay()
{

}

int Simulation::run()
{
	//main loop
	while (!m_done)
	{
		if(m_currentWeek != 12)
			simulateWeek();

		m_map->update();

		//usually should go above cutGrass()
		printStats();

		//updates
		if (cutGrass())
			m_player->update(*m_map);


		printf("%s\n", std::string(100, '\n').c_str());
		m_currentWeek++;
	}
	//delete pointers
	cleanUp();
	return 0;
}

void Simulation::simulateWeek()
{
	/*
	m_weather->stats(m_weatherStats);
	float change = m_weather->rain();
	m_map->grow(change);
	*/
	for (int i =0; i < 7; i++)
	{
		simulateDay();
	}
}

void Simulation::cleanUp()
{
	delete m_map;
	delete m_player;
}

bool Simulation::cutGrass()
{
	bool result = false;

	printf("The average tile of grass height is: %.3f\n", m_map->getAvgTileHeight());
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
	printf("Day | Week : %d | %d\n", m_currentDay, m_currentWeek);
	printf("Total grass height: %.3f\n", m_map->getTotalHeight());
	printf("Player points: %.3f\n", m_player->getPoints());
	printf("Player name: %s\n", m_player->getName().c_str());
	printf("Player symbol: %c\n", m_player->getSymbol());
}
