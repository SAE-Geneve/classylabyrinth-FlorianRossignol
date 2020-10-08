#pragma once
#include <iostream>

class Character
{
public:
	Character();
	int x;
	int y;
	int health_points;
	int attack;
	int defence;

	void Print();
	int GetHealthPoints();
	int Getattack();
	int Getdefence();
	int Getx();
	int Gety();
protected:
	int x_;
	int y_;
	int health_points_;
	int attack_;
	int defence_;
	
};