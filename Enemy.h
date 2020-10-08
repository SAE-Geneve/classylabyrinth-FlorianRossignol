#pragma once
#include <iostream>
#include "character.h"

class Enemy : public Character
{
public:

	~Enemy();
	
	void Print();
	int GetHealthPoints();
	int Getattack();
	int Getdefence();
	int Getx();
	int Gety();
protected:
	Enemy();
	void enemylost();
	std::string name = "Gob";	
};
