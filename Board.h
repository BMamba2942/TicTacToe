#pragma once

class Board
{
public:
	Board();
	~Board();
	int* getSpaces();
	void displayBoard();
	bool setSpace(int, char);
	bool gameOver();
private:
	char* board;
	int spaces;
	bool validMove(int space) { return (board[space] != ' ') ? false : true; }
	bool hasWon();
};