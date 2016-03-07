#pragma once
#include "Player.h"

class AI : public Player
{
	public:
		AI(){}
		AI(Board* gameBoard, char symbol) : Player(symbol){this->gameBoard = gameBoard;}
		~AI(){}
		virtual void move(int&, int&) = 0;
	private:
};