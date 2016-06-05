#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "constants.h"

class Map
{
public:
	Map();
	~Map();

	void init();
	void printMaps();

private:
	void printCharMap();
	void printFloatMap();

	float m_mapData[constants::MAP_SIZE][constants::MAP_SIZE];
	char m_map[constants::MAP_SIZE][constants::MAP_SIZE];
};

#endif //MAP_H