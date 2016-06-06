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
		m_name(name) {}
	Player();
	~Player();


	void setCords(int x, int y) { m_x = x, m_y = y; }
	void setX(int x) { m_x = x; }
	void setY(int y) { m_y = y; }
	void setPoints(float amount) { m_points = amount; }
	void setName(std::string name) { m_name = name; }
	void setSymbol(char symbol) { m_symbol = symbol; }

	int getX() { return m_x; }
	int getY() { return m_y; }
	float getPoints() { return m_points; }
	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }

	void init(Map &map, int cordx, int cordy);
	void update(Map &map);

private:
	void move(Map &map);
	int getInput();
	bool goodMove(int dir, Map &map);

	char m_symbol;
	std::string m_name;
	float m_points;
	int m_x;
	int m_y;
};

#endif //PLAYER_H
