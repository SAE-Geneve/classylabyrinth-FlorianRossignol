#pragma once
#include <iostream>
#include "character.h"

class Enemy : public Character
{
private:
	Enemy();
	int x;
	int y;
	int health_points = 50;
	int attack = 10;
	int defence = 2;
		
	~Enemy();
	
	void Print();
	int GetHealthPoints();
	int Getattack();
	int Getdefence();
	int Getx(int x);
	int Gety(int y);
public:
	Enemy();
	void enemylost();
	std::string name = "Gob";	
};
