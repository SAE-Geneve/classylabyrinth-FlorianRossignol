#pragma once
#include "tile.h"
#include "Enemy.h"
#include "hero.h"
#include <iostream>
#include <map>

class world
{
private:
	world();
	int GetTile(int x,int y);
	std::map<std::pair<int, int>, Enemy > local_enemy;
	int xy_local(int x,int y);
	int Get_enemy(int x,int y);
	int set_player(int x,int y);
	std::string local_world =

		"########################" // 24 * 8
		"#.....E......E.....#..P#" // P is at (22, 1)
		"#######..#####..####...#"
		"#........#.............#"
		"#.E......#...E...E.....#"
		"#..##################..#"
		"#.........E............#"
		"########################";
};
