#pragma once

#include <vector>

class Board
{
public:
	void initBoard();
	int* getOpenSpaces();
	int getSpacesCount();
	char getSpaceSymbol(int row, int column){return board[row][column];}
	void displayBoard();
	bool setSpace(int, int, char);
	int gameOver(char);
	void clearBoard();
private:
	char board[3][3];
	int spaces;
	bool validMove(int row, int column) { return (board[row][column] != ' ') ? false : true; }
	bool hasWon(char);
};
