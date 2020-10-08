#include "hero.h"
Hero::Hero() : Character(),
name("Hero"),
max_health_points_(100),
experience_(0),
health_regen_(5)
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
int Hero::Get_hero()
{
	return x;
}