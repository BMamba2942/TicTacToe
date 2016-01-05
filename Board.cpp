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

int* Board::getSpaces()
{
	int* spacesLeft = new int[10];
	int count = 0;
	for(int i = 0; i < 10; ++i)
	{
		if(board[i] == ' ')
			spacesLeft[(count++)+1] = i;
	}
	spacesLeft[0] = count;
	return spacesLeft;
}

void Board::clearBoard()
{
	for(int i = 0; i < 9; ++i)
	{
		board[i] = ' ';
	}
	spaces = 9;
}

bool Board::hasWon()
{
	/*Begin Horizontal Win checks*/
	int count = 0;
	char symbol = board[0]; //initialize symbol to find with first in search
	if(symbol != ' ')
	{
		count++;
		for(int i = 1; i < 3; ++i)
		{
			if(board[i] == symbol)
				count++;
			if(count == 3)
				return true;
		}
	}

	count = 0;
	symbol = board[3];
	if(symbol != ' ')
	{
		count++;
		for(int i = 4; i < 6; ++i)
		{
			if(board[i] == symbol)
				count++;
			if(count == 3)
				return true;
		}
	}


	count = 0;
	symbol = board[6];
	if(symbol != ' ')
	{
		count++;
		for(int i = 7; i < 9; ++i)
		{
			if(board[i] == symbol)
				count++;
			if(count == 3)
				return true;
		}
	}

	/*End Horizontal Win checks*/

	/*Begin Diagonal Win checks*/
	count = 0;
	symbol = board[0];
	if(symbol != ' ')
	{
		count++;
		for(int i = 4; i < 9; i+=4)
		{
			if(board[i] == symbol)
				count++;
			if(count == 3)
				return true;
		}
	}

	count = 0;
	symbol = board[2];
	if(symbol != ' ')
	{
		count++;
		for(int i = 4; i < 7; i+=2)
		{
			if(board[i] == symbol)
				count++;
			if(count == 3)
				return true;
		}
	}
	/*End Diagonal win checks*/

	/*Begin Column win checks*/
	count = 0;
	symbol = board[0];
	if(symbol != ' ')
	{
		count++;
		for(int i = 3; i < 7; i+=3)
		{
			if(board[i] == symbol)
				count++;
			if(count == 3)
				return true;
		}
	}

	count = 0;
	symbol = board[1];
	if(symbol != ' ')
	{
		count++;
		for(int i = 4; i < 8; i+=3)
		{
			if(board[i] == symbol)
				count++;
			if(count == 3)
				return true;
		}
	}

	count = 0;
	symbol = board[2];
	if(symbol != ' ')
	{
		count++;
		for(int i = 5; i < 9; i+=3)
		{
			if(board[i] == symbol)
				count++;
			if(count == 3)
				return true;
		}
	}

	return false;
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

int Board::gameOver()
{
	if(hasWon())
	{
		return 1; // A player has won the game
	} 
	else if(spaces == 0)
		return 0; // There was a tie
	else
		return -1; // The game is still going
}
