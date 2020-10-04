#include <map>
#include <cassert>
#include "tile.h"
#include "character.h"
#include "hero.h"
#include "Enemy.h"
// An anonymous namespace just here so you cannot access there from somewhere
// else.
namespace {

	// Map of the local space.


	// Local player stuff.


	// Map that map space to enemies.




} // End of namespace.

Enemy get_enemy(int x, int y)
{
	Enemy enemy = local_enemy[{x, y}];
	// set the local position.
	enemy.x = x;
	enemy.y = y;
	// return the enemy at the position.
	return enemy;
}

void set_player(Hero player)
{
	// Erase the local player.
	local_world[xy_local(local_player.x, local_player.y)] = '.';
	local_player = player;
	// Reinclude the new player.
	local_world[xy_local(player.x, player.y)] = 'P';
}
