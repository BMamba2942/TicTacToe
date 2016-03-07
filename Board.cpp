#include "Board.h"
#include <iostream>

void Board::initBoard()
{

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
			board[i][j] = ' ';
	}

	spaces = 9;
}

int* Board::getOpenSpaces()
{
	int* spacesAvailable = new int[this->spaces];
	int count = 0;
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
			if(board[i][j] == ' ')
				spacesAvailable[(count++)] = (i*3)+j;
	}

	return spacesAvailable;
}

int Board::getSpacesCount()
{
	return this->spaces;
}

void Board::clearBoard()
{
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
			board[i][j] = ' ';
	}
	spaces = 9;
}

bool Board::hasWon(char symbol)
{
	if(spaces > 4) return false; //Impossible to win the game before turn 5

	//Begin Row Win checks
	int count = 0;
	
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(board[i][j] == symbol)
				count++;
		}
		if(count == 3) 
			return true;
		else 
			count = 0;

	}

	//End Row Win checks

	//Begin column checks
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(board[j][i] == symbol)
				count++;
		}
		if(count == 3)
			return true;
		else
			count = 0;
	}

	//End column checks

	//Begin diagonal checks
	for(int i = 0; i < 3; ++i)
	{
		if(board[i][i] == symbol)
			count++;
	}

	if(count == 3)
		return true;
	else
		count = 0;

	int j = 2;
	for(int i = 0; i < 3; ++i)
	{
		if(board[i][j] == symbol)
			count++;
		--j;
	}

	if(count == 3)
		return true;
	else
		count = 0;

	//End diagonal checks
	return false;
}

void Board::displayBoard()
{
	for(int i = 0; i < 3; ++i)
	{
		int j;
		for(j = 0; j < 2; ++j)
			std::cout << board[i][j] << '|';
		std::cout << board[i][j] << std::endl;

	}
}

bool Board::setSpace(const int row, const int column, char symbol)
{
	if(validMove(row, column))
	{
	   board[row][column] = symbol;
	   --spaces;
	   return true;
	}
	else
		return false;
}

int Board::gameOver(char symbol)
{
	if(hasWon(symbol))
	{
		return 1; // A player has won the game
	} 
	else if(spaces == 0)
		return 0; // There was a tie
	else
		return -1; // The game is still going
}
