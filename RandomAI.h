#pragma once
#include "AI.h"
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include <iostream>

class RandomAI : public AI
{
public:
	RandomAI(){}
	RandomAI(Board* gameBoard, char symbol) : AI(gameBoard, symbol)
	{
		srand(time(NULL));
	}
	~RandomAI(){};
	int move()
	{
		gameBoard = getGameBoard();
		int* spacesAvailable = gameBoard->getSpaces();
		return spacesAvailable[1+(rand() % spacesAvailable[0])];
	}


};
