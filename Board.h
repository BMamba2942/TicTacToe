#pragma once

class Board
{
public:
	Board();
	~Board();
	int getSpaces();
	bool validMove();
	void displayBoard();
	void setSpace(int, int, char);
private:
	char* board;
	int spaces;
};