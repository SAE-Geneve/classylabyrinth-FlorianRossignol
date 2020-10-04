#include "character.h"
#include "tile.h"
#include "command.h"
#include "hero.h"
#include "Enemy.h"
#include "world.h"
#include <iostream>

void show_help() 
{
	std::cout << "Valid options:\n";
	std::cout << "\t[q]uit   -> quit the game.\n";
	std::cout << "\t[n]orth  -> move north.\n";
	std::cout << "\t[s]outh  -> move south.\n";
	std::cout << "\t[w]est   -> move west.\n";
	std::cout << "\t[e]ast   -> move east.\n";
	std::cout << "\t[a]ttack -> attack enemies.\n\n";
}

void show_state() 
{
	Hero = get_hero();
	// Show the maze to the user.
	std::cout << "Maze :\n";
	for (int i = -1; i < 2; ++i)
	{
		std::cout << "\t +---+---+---+\n\t";
		for (int j = -1; j < 2; ++j)
		{
			std::cout
				<< " | "
				<< (char)get_tile_at_position(Hero.x + j, Hero.y + i);
		}
		std::cout << " |\n";
	}
	std::cout << "\t +---+---+---+\n\n";
	// Show the player info the user.
	std::cout << "Player(" << Hero.x << ", " << Hero.y << ") :\n";
	std::cout << "\tname       : " << Hero.name << "\n";
	std::cout << "\thit points : " << Hero.health_points << "\n";
	std::cout << "\n";
	// Show the enemy that are within view of the user.
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
		{
			if (TileType::ENEMY == 
				get_tile_at_position(Hero.x + i, Hero.y + j))
			{
				Enemy enemy = get_enemy(Hero.x + i, Hero.y + j);
				std::cout 
					<< "Enemy(" << Hero.x + i 
					<< ", " << Hero.y + j 
					<< ")\n";
				std::cout << "\tname       : " << enemy.name << "\n";
				std::cout << "\thit points : " << enemy.GetHealthPoints << "\n";
				std::cout << "\n";
			}
		}
	}

	if (Hero.health_points <=0)
	{
		std::cout<< "you have lost !";

		system("pause");
		exit(0);
	}
}

CommandType get_command() 
{
	std::cout << "] ";
	std::string command_str;
	std::getline(std::cin, command_str);
	switch (command_str[0])
	{
		case 'q':
			return CommandType::QUIT;
		case 'n':
			return CommandType::NORTH;
		case 's':
			return CommandType::SOUTH;
		case 'e':
			return CommandType::EAST;
		case 'w':
			return CommandType::WEST;
		case 'a':
			return CommandType::ATTACK;
		case 'h':
		default:
			show_help();
			return CommandType::HELP;
	}
}

int main()
{
	std::cout << "Welcome in the Maze!\n\n";
	show_help();
	while (true)
	{
		show_state();
		CommandType command_type = get_command();
		switch (command_type) 
		{
			case CommandType::QUIT:
				std::cout << "bye!\n";
				return 0;
			case CommandType::NORTH:
				north();
				break;
			case CommandType::SOUTH:
				south();
				break;
			case CommandType::EAST:
				east();
				break;
			case CommandType::WEST:
				west();
				break;
			case CommandType::ATTACK:
				attack();
				break;
			case CommandType::HELP:
			default:
				break;
		}
		tick();
	}
	return 0;
}
