#pragma once
#include <iostream>

class Character
{
public:
	Character();
	int x = 22;
	int y = 1;
	int health_points = 100;
	int attack = 20;
	int defence = 5;

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