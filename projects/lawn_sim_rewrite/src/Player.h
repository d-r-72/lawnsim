#ifndef PLAYER_H
#define PLAYER_H

#include <conio.h>
#include <iostream>

#include "Map.h"

class Player
{
public:
	Player(int x, int y, float points, char symbol, std::string name)
		: m_x(x),
		m_y(y),
		m_points(points),
		m_symbol(symbol),
		m_name(name),
		m_doneMowing(false),
		m_printFloatMap(false),
		m_mowerFuel(4.0f) {}
	Player();
	~Player();


	void setCords(int x, int y) { m_x = x, m_y = y; }
	void setX(int x) { m_x = x; }
	void setY(int y) { m_y = y; }
	void setPoints(float amount) { m_points = amount; }
	void setName(std::string name) { m_name = name; }
	void setSymbol(char symbol) { m_symbol = symbol; }
	void setFuelLevel(float level) { m_mowerFuel = level; }

	void givePoints(float amount) { m_points += amount; }

	int getX() { return m_x; }
	int getY() { return m_y; }
	float getPoints() { return m_points; }
	float getFuelLevel() { return m_mowerFuel; }
	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }

	void init(Map &map, int cordx, int cordy);
	void update(Map &map);

private:
	int getInput();

	void move(Map &map);

	bool goodMove(int dir, Map &map);

	bool m_printFloatMap;
	bool m_doneMowing;

	char m_symbol;
	
	std::string m_name;
	
	float m_points;
	float m_mowerFuel;

	int m_x;
	int m_y;
};

#endif //PLAYER_H
