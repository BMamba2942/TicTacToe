#pragma once

class Player
{
	public:
		Player(){};
		~Player(){};
		char getSymbol();
		void setSymbol();
		virtual void move() = 0;
	private:
		char symbol;
};