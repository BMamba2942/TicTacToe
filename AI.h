#pragma once
#include "Player.h"

class AI : public Player
{
	public:
		AI(){}
		AI(Board* gameBoard, char symbol) : Player(symbol){this->gameBoard = gameBoard;}
		~AI(){}
		virtual int move() = 0;
	private:
};