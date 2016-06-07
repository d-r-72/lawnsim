#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>

#include "constants.h"

class Weather
{
public:
	Weather() : m_flooded(false) { engine.seed(time(0)); }
	~Weather();

	float rain();

	bool isFlooded() { return m_flooded; }

	void stats(bool print);

	int getRand(int start, int end);

private:
	std::default_random_engine engine;
	bool m_printStats;
	bool m_flooded;
};

#endif //WEATHER_H