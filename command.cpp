#include <vector>
#include "command.h"
#include "hero.h"
#include "Enemy.h"
#include "world.h"
namespace {

	void cross_attack(Hero player, Enemy enemy) 
	{
		// Max is there to avoid giving health point in case too high defence.
		Hero.GetHealthPoints -= std::max(0, enemy.Getattack- player.Getdefence());
		enemy.GetHealthPoints -= std::max(0, player.Getattack - enemy.Getdefense);
		set_player(player);
		set_enemy(enemy, enemy.x, enemy.y);
	}

}

void north()
{
	Hero player = get_player();
	// Get the location at north of the current player.
	TileType tile_type = get_tile_at_position(player.x, player.y - 1);
	// If the location is not empty do NOTHING!
	if (tile_type != TileType::EMPTY)
		return;
	player.y -= 1;
	set_player(player);
}

void south()
{
	Hero player = get_player();
	// Get the location at north of the current player.
	TileType tile_type = get_tile_at_position(player.x, player.y + 1);
	// If the location is not empty do NOTHING!
	if (tile_type != TileType::EMPTY)
		return;
	player.y += 1;
	set_player(player);
}

void east()
{
	Player player = get_player();
	// Get the location at north of the current player.
	TileType tile_type = get_tile_at_position(player.x + 1, player.y);
	// If the location is not empty do NOTHING!
	if (tile_type != TileType::EMPTY)
		return;
	player.x += 1;
	set_player(player);
}

void west()
{
	Player player = get_player();
	// Get the location at north of the current player.
	TileType tile_type = get_tile_at_position(player.x - 1, player.y);
	// If the location is not empty do NOTHING!
	if (tile_type != TileType::EMPTY)
		return;
	player.x -= 1;
	set_player(player);
}

void attack()
{
	Player player = get_player();
	std::vector<Enemy> enemy_vec;
	// for now only attack enemy that are in strait line +.
	if (TileType::ENEMY == get_tile_at_position(player.x, player.y - 1))
		enemy_vec.push_back(get_enemy(player.x, player.y - 1));
	if (TileType::ENEMY == get_tile_at_position(player.x, player.y + 1))
		enemy_vec.push_back(get_enemy(player.x, player.y + 1));
	if (TileType::ENEMY == get_tile_at_position(player.x - 1, player.y))
		enemy_vec.push_back(get_enemy(player.x - 1, player.y));
	if (TileType::ENEMY == get_tile_at_position(player.x + 1, player.y))
		enemy_vec.push_back(get_enemy(player.x + 1, player.y));
	for (const auto& enemy : enemy_vec)
		cross_attack(player, enemy);
}

void tick()
{
	// FIXME Suppose to have enemy moving soon(tm).
	// Life regen.
	Player player = get_player();
	player.health_points += player.health_regen;
	player.health_points = 
		std::min(player.health_points, player.max_health_points);
}
