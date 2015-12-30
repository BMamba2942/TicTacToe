#pragma once
#include "Player.h"

class AI : public Player
{
	public:
		AI(){};
		~AI(){};
		virtual int move() = 0;
	private:
};