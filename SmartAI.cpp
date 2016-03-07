#include "SmartAI.h"

//#define DEBUG // Uncomment this to enable debugging output
//Debugging includes here
#ifdef DEBUG
   #include <iostream>
#endif


void SmartAI::move(int& row, int& column)
{
	int selection;
	gameBoard = getGameBoard();
	char oppSymbol = (this->symbol == 'X') ? 'O' : 'X';
	int* spacesAvailable = gameBoard->getOpenSpaces();
	int spacesLeft = gameBoard->getSpacesCount();

	
	if(blockOrWin(row, column, this->symbol)) //check for win first
		return; 
	else if(blockOrWin(row, column, oppSymbol)) //then check for block
		return;
	else //if no win or block, then choose a random spot
	{
		selection = spacesAvailable[rand() % spacesLeft];
		row = selection / 3;
		column = selection - (row * 3);
	}
}

bool SmartAI::blockOrWin(int& row, int& column, char checkSymbol)
{
	int empty = 0, count = 0, emptyRow = 0, emptyColumn = 0; //initialize variables
	bool madeMove = false;
	//Rows
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(gameBoard->getSpaceSymbol(i, j) == checkSymbol)
				count++;
			else if(gameBoard->getSpaceSymbol(i, j) == ' ')
			{
				empty++;
				emptyRow = i;
				emptyColumn = j;
			}
		}
		if(count == 2 && empty == 1)
		{
			row = emptyRow;
			column = emptyColumn;
			return true;
		}
		else
		{
			count = 0;
			empty = 0;
		}
	}
	//End rows

	//Columns
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(gameBoard->getSpaceSymbol(j, i) == checkSymbol)
				count++;
			else if(gameBoard->getSpaceSymbol(j, i) == ' ')
			{
				empty++;
				emptyRow = j;
				emptyColumn = i;
			}
		}
		if(count == 2 && empty == 1)
		{
			row = emptyRow;
			column = emptyColumn;
			return true;
		}
		else
		{
			count = 0;
			empty = 0;
		}
	}
	//End columns

	//Diagonals
	for(int i = 0; i < 3; ++i)
	{
		if(gameBoard->getSpaceSymbol(i, i) == checkSymbol)
			count++;
		else if(gameBoard->getSpaceSymbol(i, i) == ' ')
		{
			empty++;
			emptyRow = emptyColumn = i;
		}
	}

	if(count == 2 && empty == 1)
	{
		row = emptyRow;
		column = emptyColumn;
		return true;
	}
	else
	{
		count = 0;
		empty = 0;
	}

	int j = 2;
	for(int i = 0; i < 3; ++i)
	{
		if(gameBoard->getSpaceSymbol(i, j) == checkSymbol)
			count++;
		else if(gameBoard->getSpaceSymbol(i, j) == ' ')
		{
			empty++;
			emptyRow = i;
			emptyColumn = j;
		}
		--j;
	}
	if(count == 2 && empty == 1)
	{
		row = emptyRow;
		column = emptyColumn;
		return true;
	}
	//End diagonals

	return false;
}