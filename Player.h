#pragma once

class Player
{
	public:
		Player(){};
		~Player(){};
		char getSymbol(){return symbol;}
		void setSymbol(char symbol){this->symbol = symbol;}
		virtual int move() = 0;
	protected:
		char symbol;
};