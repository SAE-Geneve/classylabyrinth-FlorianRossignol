#include "hero.h"
#include "world.h"
#include "Enemy.h"
#include "tile.h"
#include <iostream>


world::world()
{
	GetTile();
	Get_enemy();
	set_player();
	xy_local();
	local_enemy;
}

std::map<std::pair<int, int>, Enemy> local_enemy;
Hero local_player{};
void set_enemy(Enemy enemy, int x, int y);
Enemy get_enemy(int x, int y);
Hero get_player();

int world::GetTile(int x, int y)
{
	return (TileType)local_world[xy_local(x, y)];
}

int world::xy_local(int x,int y)
{
	// We want the local array to be bound to the borders.
	if (x < 0) x = 0;
	if (x > 23) x = 23;
	if (y < 0) y = 0;
	if (y > 7) y = 7;
	// Return the position within the local world of the cursor.
	// As the array is singular dimention we use the largest value to
	// split it.
	return x + y * 24;
}

int world::Get_enemy(int x,int y)
{
	Enemy enemy = local_enemy[{ enemy.x, enemy.y }];
	// set the local position.
	enemy.x() = x;
	enemy.y() = y;
	// return the enemy at the position.
	return enemy;
}

int world::set_player(int x,int y)
{
	// Erase the local player.
	Hero local_player;
	local_world[xy_local(local_player.x, local_player.y)] = '.';
	// Reinclude the new player.
	local_world[xy_local(Hero.x, Hero.y)] = 'P';
}


Hero get_player()
{
	return local_player;
}