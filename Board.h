#pragma once

#include <vector>

class Board
{
public:
	void initBoard();
	int* getOpenSpaces();
	int getSpacesCount();
	char getSpaceSymbol(int space){return board[space];}
	void displayBoard();
	bool setSpace(int, char);
	int gameOver();
	void clearBoard();
private:
	std::vector<char> board;
	int spaces;
	bool validMove(int space) { return (board[space] != ' ') ? false : true; }
	bool hasWon();
};
