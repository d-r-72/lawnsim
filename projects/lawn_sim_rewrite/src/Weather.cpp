#include "Weather.h"

Weather::~Weather()
{

}

float Weather::rain()
{
	float result = 0.0f;
	int startDay = getRand(1, 7);	
	int temp = (7 - startDay);
	int duration = getRand(0, temp);

	if(duration % 2 == 0)
		result = 0.0f;
	else
	{
		for (int i = startDay; i < (startDay + duration); i++)
		{
			result += 0.10f;
		}
	}

	if(m_printStats)
	{
		printf("\n----------WEATHER STATS----------\n");
		printf("Startday: %d\nDuration: %d\nMax Duration: %d\n", startDay, duration, 7 - startDay);
		printf("---------------------------------\n\n");
	}

	return result;
}

void Weather::stats(bool print)
{
	m_printStats = print;
}

int Weather::getRand(int start, int end)
{
	std::uniform_int_distribution<int> distribution(start, end);
	int rand = distribution(engine);
	return rand;
}
