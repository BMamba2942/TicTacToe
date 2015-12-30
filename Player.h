#pragma once
#include "Board.h"

class Player
{
	public:
		Player(){};
		~Player(){};
		char getSymbol(){return symbol;}
		void setSymbol(char symbol){this->symbol = symbol;}
		void setGameBoard(Board* gameBoard){this->gameBoard = gameBoard;}
		Board* getGameBoard(){return this->gameBoard;}
		virtual int move() = 0;
	protected:
		char symbol;
		Board* gameBoard;
};