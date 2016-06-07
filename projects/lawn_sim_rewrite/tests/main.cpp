#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>

int main()
{
	bool done = false;

	std::default_random_engine engine(time(0));
	std::uniform_int_distribution<int> distribution(0, 10);

	while(!done)
	{
		std::cout << distribution(engine) << std::endl;
		Sleep(1000);
	}

	int k;
	std::cin >> k;
	return 0;
}