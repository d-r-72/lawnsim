#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::init(Map &map)
{
	map.setTile(m_x, m_y, '@');
}

void Player::update(Map &map)
{
	move(map);
}

void Player::move(Map &map)
{
	int dir = getInput();
	switch (dir)
	{
	case 1:
		if (goodMove(dir, map))
		{
			map.setTile(m_x, m_y - 1, '@');
			map.setTile(m_x, m_y, '^');
			setCords(m_x, m_y - 1);
		}
		break;
	case 2:
		if (goodMove(dir, map))
		{
			map.setTile(m_x + 1, m_y, '@');
			map.setTile(m_x, m_y, '^');
			setCords(m_x + 1, m_y);
		}
		break;
	case 3:
		if (goodMove(dir, map))
		{
			map.setTile(m_x, m_y + 1, '@');
			map.setTile(m_x, m_y, '^');
			setCords(m_x, m_y + 1);
		}
		break;
	case 4:
		if (goodMove(dir, map))
		{
			map.setTile(m_x - 1, m_y, '@');
			map.setTile(m_x, m_y, '^');
			setCords(m_x - 1, m_y);
		}
		break;
	case 5:
		break;
	default:
		break;
	}
}

int Player::getInput()
{
	int result;
	printf("Please enter a movement command W.A.S.D or Q to quit! ");
	char temp = _getch();
	switch (temp)
	{
	case 'w':
	case 'W':
		result = 1;
		break;
	case 'd':
	case 'D':
		result = 2;
		break;
	case 's':
	case 'S':
		result = 3;
		break;
	case 'a':
	case 'A':
		result = 4;
		break;
	case 'q':
	case 'Q':
		result = 5;
		break;
	default:
		printf("\nIncorrect user input, press any key too exit...");
		_getch();
		exit(-1);
		break;
	}
	return result;
}

bool Player::goodMove(int dir, Map &map)
{
	bool result = false;
	char temp;
	if (dir == 1)
		map.getTile(m_x, m_y - 1, temp);
	if (dir == 2)
		map.getTile(m_x + 1, m_y, temp);
	if (dir == 3)
		map.getTile(m_x, m_y + 1, temp);
	if (dir == 4)
		map.getTile(m_x - 1, m_y, temp);

	if (temp == '#')
		result = true;
	if (temp == '^')
		result = true;

	return result;
}
