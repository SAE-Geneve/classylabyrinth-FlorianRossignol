#include <iostream>
#include "tile.h"
#include "command.h"

void show_help() 
{
	std::cout << "Valid options:\n";
	std::cout << "\t[q]uit  -> quit the game.\n";
	std::cout << "\t[n]orth -> move north.\n";
	// TODO fill up the rest!
}

void show_state() 
{
	std::cout << "Maze :\n";
	// TODO complete me!
	std::cout << "Player :\n";
	// TODO complete me!
	// Now check if there is an enemy within range.
	// for each enemy within range:
	// show enemy description.
}

CommandType get_command() 
{
	std::cout << "] ";
	std::string value;
	std::getline(std::cin, value);
	switch (value[0])
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
	std::cout << "Welcome in the Maze!\n";
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
				tick();
				break;
			case CommandType::SOUTH:
				south();
				tick();
				break;
			case CommandType::EAST:
				east();
				tick();
				break;
			case CommandType::WEST:
				west();
				tick();
				break;
			case CommandType::ATTACK:
				attack();
				tick();
				break;
			case CommandType::HELP:
			default:
				tick();
				break;
		}
	}
	return 0;
}