#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::init(Map &map, int cordx, int cordy)
{
	//set the player to a certain defined tile
	map.setTile(cordx, cordy, '@');
}

void Player::update(Map &map)
{
	map.reGrowth();
	map.setPlayer(getX(), getY());
	//move the player
	while (!m_doneMowing)
	{
		printf("%s", std::string(100, '\n').c_str());
		if (m_printFloatMap)
			map.printFloatMap();
		map.printCharMap();
		move(map);
		map.update();
	}
	m_doneMowing = false;
}

void Player::move(Map &map)
{
	int dir = getInput();
	switch (dir)
	{
	case 1:
		if (goodMove(dir, map))
		{
			/*set the next tile to player symbol 
			then set the current tile to the 'cut' 
			character then set the players cords*/
			map.setTile(m_x, m_y - 1, '@');
			map.setTile(m_x, m_y, '^');
			setCords(m_x, m_y - 1);
			map.cutGrassTile(m_x, m_y + 1, 0.5f);
		}
		break;
	case 2:
		if (goodMove(dir, map))
		{
			map.setTile(m_x + 1, m_y, '@');
			map.setTile(m_x, m_y, '^');
			setCords(m_x + 1, m_y);
			map.cutGrassTile(m_x - 1, m_y, 0.5f);
		}
		break;
	case 3:
		if (goodMove(dir, map))
		{
			map.setTile(m_x, m_y + 1, '@');
			map.setTile(m_x, m_y, '^');
			setCords(m_x, m_y + 1);
			map.cutGrassTile(m_x, m_y - 1, 0.5f);
		}
		break;
	case 4:
		if (goodMove(dir, map))
		{
			map.setTile(m_x - 1, m_y, '@');
			map.setTile(m_x, m_y, '^');
			setCords(m_x - 1, m_y);
			map.cutGrassTile(m_x + 1, m_y, 0.5f);
		}
		break;
	case 5:
		m_doneMowing = true;
		break;
	case 6:
		m_printFloatMap = true;
	default:
		break;
	}
}

int Player::getInput()
{
	int result = 0;
	printf("Please enter a movement command W.A.S.D or Q to quit! (6 to print float map): ");
	char temp = _getch();
	printf("\n");
	//change input from a character to a int
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
	case 't':
	case 'T':
		result = 6;
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
	//check to see if the next move is a usable tile symbol
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
