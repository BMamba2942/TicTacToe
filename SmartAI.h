#pragma once
#include "AI.h"
#include <cstdlib>
#include <ctime>

class SmartAI : public AI
{
	public:
		SmartAI(){};
		int move();
	private:
		int blockOrWin(char);
};
