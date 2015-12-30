#include "Board.h"
#include <iostream>

Board::Board()
{
	board = new char[9];
	for(int i = 0; i < 9; ++i)
	{
		board[i] = ' ';
	}

	spaces = 9;
}

Board::~Board()
{
	delete [] board;
}

void Board::displayBoard()
{
	for(int i = 0; i < 9; ++i)
	{
		if((!((i+1) % 3))) 
			std::cout << board[i] << std::endl;
		else
			std::cout << board[i] << '|';

	}
}

bool Board::setSpace(int space, char symbol)
{
	if(validMove(space))
	{
	   board[space] = symbol;
	   --spaces;
	   return true;
	}
	else
		return false;
}

bool Board::gameOver()
{
	if(spaces == 0)
		return true;
}