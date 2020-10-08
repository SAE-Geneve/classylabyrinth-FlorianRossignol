#pragma once
#include <iostream>
#include "character.h"

class Hero : public Character
{
public:
	Hero();

	std::string name = "Hero";
	
	void Print();
	int GetHealthPoints();
	int Getattack();
	int Getdefence();
	int Getx();
	int Gety();
	int Get_hero();
protected:
	int max_health_points_;
	int experience_= 0;
	int health_regen_ = 5;
};