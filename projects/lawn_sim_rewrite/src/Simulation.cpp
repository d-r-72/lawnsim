#include "Simulation.h"

Simulation::Simulation()
{
	m_color->setColorWhite();
	printf("Weather stats? ");
	char in = _getch();
	printf("\n");
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
	m_color = new Color();

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
	int dayCount = 1;
	//main loop
	while (!m_done)
	{
		m_color->setColorRed();
		printf("Day | Week : %d | %d\n", m_currentDay, m_currentWeek);
		m_color->setColorWhite();

		if(m_currentWeek != 12)
			simulateWeek();

		m_map->update();

		//usually should go above cutGrass()
		printStats();

		//updates
		if (cutGrass())
			m_player->update(*m_map);
		else
			dayCount++;

		if (dayCount == 3)
			m_player->setFuelLevel(2.0f), dayCount = 0;


		Sleep(2000);
		printf("%s\n", std::string(100, '\n').c_str());
		m_currentWeek++;
	}
	//delete pointers
	cleanUp();
	return 0;
}

void Simulation::simulateWeek()
{
	
	m_weather->stats(m_weatherStats);
	float change = m_weather->rain();
	m_map->grow(change);
	
	for (int i = 0; i < 7; i++)
	{
		simulateDay();
	}
}

void Simulation::cleanUp()
{
	delete m_color;
	delete m_map;
	delete m_player;
}

bool Simulation::cutGrass()
{
	bool result = false;

	m_map->printFloatMap();
	printf("Would you like to mow? (y,n)");
	char answer;
	answer = _getch();
	if (answer == 'y')
		result = true;
	if (answer == 'Y')
		result = true;

	if (m_player->getFuelLevel() < 0.2f)
	{
		result = false;
		printf("\nNot enough fuel!");
	}

	printf("\n");
	return result;
}

void Simulation::printStats()
{
	printf("\n----------PLAYER STATS----------\n");
	printf("Player points: %.3f\n", m_player->getPoints());
	printf("Player name: %s\n", m_player->getName().c_str());
	printf("Player symbol: %c\n", m_player->getSymbol());
	printf("Mower fuel level: %.3f\n", m_player->getFuelLevel());
	printf("--------------------------------\n\n");

	printf("\n----------MAP STATS----------\n");
	printf("Map grass height: %.3f\n", m_map->getTotalHeight());
	printf("-----------------------------\n\n");
	//printf("Total grass height: %.3f\n", m_map->getTotalHeight());
}
