#include "Board.h"
#include "AI.h"
#include "RandomAI.h"
#include "SmartAI.h"
#include "Human.h"
#include <iostream>

enum GAME_TYPE {AI_BATTLE, ONE_PLAYER, TWO_PLAYER};

void aiBattle()
{

}

void onePlayerGame()
{

}

void twoPlayerGame()
{

}

void menu()
{
	int selection = 0, temp;

	std::cout << "Welcome to Tic Tac Toe!\n\n";
	std::cout << "Please select the number of players participating:\n";
	std::cout << "1. 0 players\n";
	std::cout << "2. 1 player\n";
	std::cout << "3. 2 players\n";
	std::cin >> temp;
	do
	{
		switch(temp)
		{
			case 1: aiBattle();
			break;
			case 2: onePlayerGame();
			break;
			case 3: twoPlayerGame();
			break;
			default: std::cout << "Please select a valid option (1, 2, or 3)\n";
			         std::cin >> temp;
		}

	}
	while(temp < 1 && temp > 3);
}

void game(int gameType)
{
	switch(gameType)
	{
		Player* player1; Player* player2;
		player1 = new RandomAI();
		player2 = new SmartAI();
		player1->move();
		player2->move();
	};
}

int main()
{
	Board* gameBoard = new Board();
	menu();
	gameBoard->displayBoard();

	return 0;
}