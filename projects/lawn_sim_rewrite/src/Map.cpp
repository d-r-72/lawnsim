#include "Map.h"



Map::Map()
{
}


Map::~Map()
{
}

void Map::init()
{
	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			m_map[i][j] = '#';
			m_mapData[i][j] = constants::INITIAL_GRASS_HEIGHT;
		}
	}
}

void Map::printCharMap()
{
	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			printf("  %c  ", m_map[i][j]);
		}
		printf("\n");
	}
}

void Map::printFloatMap()
{
	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			printf("  %.3f  ", m_mapData[i][j]);
		}
		printf("\n");
	}
}

void Map::printMaps()
{
	printCharMap();
	printFloatMap();
}
