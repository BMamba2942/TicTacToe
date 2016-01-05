#pragma once
#include "AI.h"
#include <cstdlib>
#include <ctime>

class SmartAI : public AI
{
	public:
		SmartAI(){}
		SmartAI(Board* gameBoard, char symbol): AI(gameBoard, symbol){srand(time(NULL));}
		int move();
	private:
		int blockOrWin(char);
};
