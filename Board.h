#pragma once

class Board
{
public:
	Board();
	~Board();
	int* getSpaces();
	char getSpaceSymbol(int space){return board[space];}
	void displayBoard();
	bool setSpace(int, char);
	int gameOver();
	void clearBoard();
private:
	char* board;
	int spaces;
	bool validMove(int space) { return (board[space] != ' ') ? false : true; }
	bool hasWon();
};
