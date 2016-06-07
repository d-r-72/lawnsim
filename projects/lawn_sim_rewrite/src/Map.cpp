#include "Map.h"



Map::Map()
{
	m_grassHeight = 36.0f;
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
			m_mapData[i][j] = (m_grassHeight) / (float)(constants::MAP_SIZE * constants::MAP_SIZE);
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

char Map::getTileSymbol(int x, int y)
{
	return m_map[y][x];
}

float Map::getAvgTileHeight()
{
	return m_grassHeight / (constants::MAP_SIZE * constants::MAP_SIZE);
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

void Map::cutGrassTile(int x, int y, float amount)
{
	if(m_mapData[y][x] > amount)
		m_mapData[y][x] -= amount;
}

void Map::update()
{
	m_grassHeight = 0;
	//map update function; just prints the character map
	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			m_grassHeight += m_mapData[i][j];
		}
	}
}
