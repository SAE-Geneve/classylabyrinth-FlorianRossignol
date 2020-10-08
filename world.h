#pragma once
#include "tile.h"
#include "Enemy.h"
#include "hero.h"
#include <iostream>
#include <map>

class world
{
	public:
	world();
	int GetTile();
	std::map<std::pair<int, int>, Enemy > local_enemy;
	int xy_local();
	int Get_enemy();
	int set_player();

protected:

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
