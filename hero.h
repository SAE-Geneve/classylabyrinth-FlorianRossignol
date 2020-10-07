#pragma once
#include <iostream>
#include "character.h"

class Hero : public Character
{
public:
	Hero();

	int x = 22;
	int y = 1;
	int health_points = 100;
	int attack = 20;
	int defence = 5;
	std::string name = "Hero";
	
	void Print();
	int GetHealthPoints();
	int Getattack();
	int Getdefence();
	int Getx();
	int Gety();
	int Get_hero();
private:
	int max_health_points_;
	int experience_= 0;
	int health_regen_ = 5;
};