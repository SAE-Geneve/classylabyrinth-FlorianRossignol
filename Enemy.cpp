#include "Enemy.h"
#include "character.h"
#include <iostream>
Enemy::Enemy(int x,
	int y,
	int health_points,
	int attack,
	int defence) : Character(x,y, health_points, attack, defence)
{

}

Enemy::~Enemy()
{
	
}


int Enemy::GetHealthPoints()
{
	return health_points_;
}

int Enemy::Getattack()
{
	return attack_;
}

int Enemy::Getdefence()
{
	return defence_;
}
int Enemy::Getx()
{
	return x_;
}

int Character::Gety()
{
	return y_;
}