#include "Map.h"



Map::Map()
{
	m_grassHeight = 36.0f;
	m_color = new Color();
}


Map::~Map()
{
	delete m_color;
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
			if (m_map[i][j] == '@')
			{
				m_color->setColorWhite();
				printf("  %c  ", m_map[i][j]);
			}
			else if ((m_map[i][j] == '^') || (m_map[i][j] == '<') || (m_map[i][j] == '>'))
			{
				m_color->setColorDarkGreen();
				printf("  %c  ", m_map[i][j]);
				m_color->setColorWhite();
			}
			else if (m_map[i][j] == '#')
			{
				m_color->setColorGreen();
				printf("  %c  ", m_map[i][j]);
				m_color->setColorWhite();
			}
		}
		printf("\n\n");
	}
}

void Map::printFloatMap()
{
	//print the map of floats
	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			if (m_map[i][j] == '@')
			{
				m_color->setColorBlue();
				printf(" %.1f ", m_mapData[i][j]);
				m_color->setColorWhite();
			}
			else
				printf(" %.1f ", m_mapData[i][j]);
		}
		printf("\n\n");
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

float Map::getTileHeight(int x, int y)
{
	return m_mapData[y][x];
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
	//map update function
	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			m_grassHeight += m_mapData[i][j];
		}
	}
}

void Map::reGrowth()
{
	for (int i = 0; i < constants::MAP_SIZE; i++)
	{
		for (int j = 0; j < constants::MAP_SIZE; j++)
		{
			if(m_mapData[i][j] >= 1.0f)
			{
				m_map[i][j] = '#';
			}
		}
	}
}

void Map::setPlayer(int x, int y)
{
	m_map[y][x] = '@';
}
