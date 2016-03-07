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
	void move(int& row, int& column)
	{
		gameBoard = getGameBoard();
		int* spacesAvailable = gameBoard->getOpenSpaces();
		int spacesLeft = gameBoard->getSpacesCount();
		int selection = spacesAvailable[(rand() % spacesLeft)];

		row = selection / 3;
		column = selection - (row * 3);
	}


};
