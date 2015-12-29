#pragma once
#include "Player.h"

class AI : public Player
{
	public:
		AI(){};
		~AI(){};
		virtual void move() = 0;
	private:
};