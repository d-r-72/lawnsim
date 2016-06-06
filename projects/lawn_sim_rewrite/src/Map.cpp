#include "Map.h"



Map::Map()
{
}


Map::~Map()
{
}

void Map::init()
{
	//set the map to #'s and set the data map to appropriate height
	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			m_map[i][j] = '#';
			m_mapData[i][j] = constants::INITIAL_GRASS_HEIGHT;
			m_grassHeight += m_mapData[i][j];
		}
	}
}

void Map::printCharMap()
{
	//print the map of characters
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
	//print the map of floats
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
	//print both the maps
	printCharMap();
	printFloatMap();
}

void Map::getTile(int x, int y, char &sym)
{
	//get the character of a certain tile
	sym = m_map[y][x];
}

void Map::setTile(int x, int y, char symbol)
{
	//set the character of a certain tile
	m_map[y][x] = symbol;
}

float Map::getAvgTileHeight()
{
	float counter = 0;

	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			counter += m_mapData[i][j];
		}
	}
	m_grassHeight = counter;
	counter /= (constants::MAP_SIZE * constants::MAP_SIZE);

	return counter;
}

void Map::grow(float amount)
{
	//increase each tiles height
	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			m_mapData[i][j] += amount;
		}
	}
}

void Map::update()
{
	//map update function; just prints the character map
	printCharMap();
}
