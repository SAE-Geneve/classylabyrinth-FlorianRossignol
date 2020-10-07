#include "hero.h"
Hero::Hero(
	int x,
	int y,
	int health_points,
	int attack,
	int defence,
	std::string name) : Character(x, y, health_points, attack, defence)
{
}
int Hero::GetHealthPoints()
{
	return health_points_;
}

int Hero::Getattack()
{
	return attack_;
}

int Hero::Getdefence()
{
	return defence_;
}
int Hero::Getx()
{
	return x_;
}

int Character::Gety()
{
	return y_;
}
int Hero::Get_hero(int x, int y)
{
	return x;
}
