#include <iostream>

#include "Map.h"

int main()
{
	Map *map;
	map = new Map();
	map->init();
	map->printMaps();

	int k;
	std::cin >> k;
	return 0;
}