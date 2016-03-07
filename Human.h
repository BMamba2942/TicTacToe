#pragma once
#include "Player.h"
#include <iostream>

class Human : public Player
{
public:
	Human(){}
	Human(char symbol) : Player(symbol){}
	~Human(){}
	void move(int& row, int& column)
	{
		//int row, column;
		std::cout << "Where would you like to move?\n";
		std::cout << "1. Top Row\n2. Middle Row\n3. Bottom Row\n";
		std::cin >> row;
		while(row < 1 || row > 3)
		{
			std::cout << "Input invalid. Please select a valid row (1, 2, or 3)\n";
			std::cin >> row;
		}
		row--;
		std::cout << "1. Left Column\n2. Middle Column\n3. Right Column\n";
		std::cin >> column;
		while(column < 1 || column > 3)
		{
			std::cout << "Input invalid. Please select a valid row (1, 2, or 3)\n";
			std::cin >> column;
		}
		column--;

	}
};
