#pragma once
#include "Board.h"

class Player
{
	public:
		Player(){};
		Player(char symbol){wins = 0; ties = 0; losses = 0;this->symbol = symbol;}
		~Player(){}
		char getSymbol(){return symbol;}
		void setSymbol(char symbol){this->symbol = symbol;}
		void setGameBoard(Board* gameBoard){this->gameBoard = gameBoard;}
		Board* getGameBoard(){return this->gameBoard;}
		void incrementWins(){wins++;}
		void incrementLosses(){losses++;}
		void incrementTies(){ties++;}
		int getWins(){return wins;}
		int getTies(){return ties;}
		int getLosses(){return losses;}
		virtual int move() = 0;
	protected:
		char symbol;
		Board* gameBoard;
		int wins;
		int ties;
		int losses;
};