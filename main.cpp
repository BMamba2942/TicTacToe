#include "Board.h"
#include "AI.h"
#include "RandomAI.h"
#include "SmartAI.h"
#include "Human.h"
#include <iostream>

enum GAME_TYPE {AI_BATTLE, ONE_PLAYER, TWO_PLAYER};

void aiBattle(Board* gameBoard)
{

}

void onePlayerGame(Board* gameBoard)
{

}

void twoPlayerGame(Board* gameBoard)
{
	Player* player1 = new Human();
	player1->setSymbol('X');
	Player* player2 = new Human();
	player2->setSymbol('O');
	while(!gameBoard->gameOver())
	{
		std::cout << "Player 1's turn\n";
		while(!gameBoard->setSpace(player1->move(), player1->getSymbol()))
		{
			std::cout << "That was an invalid move. Please move again\n";
		}
		gameBoard->displayBoard();
		if(gameBoard->gameOver()) break;
		std::cout << "Player 2's turn\n";
		while(!gameBoard->setSpace(player2->move(), player2->getSymbol()))
		{
			std::cout << "That was an invalid move. Please move again\n";
		}
		gameBoard->displayBoard();
	}
}

void menu(Board* gameBoard)
{
	int selection = 0, temp;
	bool correct = false;
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
			case 1: aiBattle(gameBoard); correct = true;
			break;
			case 2: onePlayerGame(gameBoard); correct = true;
			break;
			case 3: twoPlayerGame(gameBoard); correct = true;
			break;
			default: std::cout << "Please select a valid option (1, 2, or 3)\n";
			         std::cin >> temp;
			break;
		}

	}
	while(!correct);
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
	menu(gameBoard);

	return 0;
}