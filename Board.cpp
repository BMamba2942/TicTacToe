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

void Board::setSpace(int row, int column, char symbol)
{
	board[(row*3)+column] = symbol;
}
