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

	void getTile(int x, int y, char &sym);
	void setTile(int x, int y, char symbol);
	float getTotalHeight() { return m_grassHeight; }

	char getTileSymbol(int x, int y);
	float getAvgTileHeight();

	void grow(float amount);
	void cutGrassTile(int x, int y, float amount);

	void update();
	void printFloatMap();
	void printCharMap();

private:
	float m_grassHeight;

	float m_mapData[constants::MAP_SIZE][constants::MAP_SIZE];
	char m_map[constants::MAP_SIZE][constants::MAP_SIZE];
};

#endif //MAP_H