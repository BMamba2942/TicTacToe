#pragma once 
#include "AI.h"
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include <iostream>

class RandomAI : public AI
{
public:
	RandomAI()
	{
		srand(time(NULL));
	}
	~RandomAI(){};
	int move()
	{
		Board* gameBoard = getGameBoard();
		int* spacesAvailable = gameBoard->getSpaces();
		for(int i = 1; i < spacesAvailable[0]; i++)
		{
			std::cout << spacesAvailable[i] << std::endl;
		}
		return spacesAvailable[1+(rand() % spacesAvailable[0])];
	}


};