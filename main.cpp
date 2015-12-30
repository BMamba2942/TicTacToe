#include "Board.h"
#include "AI.h"
#include "RandomAI.h"
#include "SmartAI.h"
#include "Human.h"
#include <iostream>

void gameLogic(Board* gameBoard, Player* player1, Player* player2)
{
	int check;
	while(!gameBoard->gameOver())
	{
		std::cout << "Player 1's turn\n";
		while(!gameBoard->setSpace(player1->move(), player1->getSymbol()))
		{
			std::cout << "That was an invalid move. Please move again\n";
		}
		gameBoard->displayBoard();
		if(gameBoard->gameOver()) break; //If the game has been won or there was a tie, break;
		std::cout << "Player 2's turn\n";
		while(!gameBoard->setSpace(player2->move(), player2->getSymbol()))
		{
			std::cout << "That was an invalid move. Please move again\n";
		}
		gameBoard->displayBoard();
	}
}

void aiBattle(Board* gameBoard)
{
	std::cout << "Not yet implemented :(\n";
}

void onePlayerGame(Board* gameBoard)
{
	int choice = 0, choice2 = 0;
	Player* player1, *player2;
	std::cout << "Would you like to play against the random AI(1) or the better AI(2)?\n";
	std::cin >> choice;
	while(choice != 1 && choice != 2)
	{
		std::cout << "Please select a valid option (1 for random, 2 for better AI)\n";
		std::cin >> choice;
	}
	
	std::cout << "Would you like to go first(3) or have the AI go first(4)?\n";
	std::cin >> choice2;
	while(choice2 != 3 && choice2 != 4)
	{
		std::cout << "Please select a valid option (3 for you, 4 for the AI going first)\n";
		std::cin >> choice2;
	}
	

	switch(choice * choice2)
	{
		//random AI, with player going first
		case 3: player1 = new Human();
				player2 = new RandomAI();
				player2->setGameBoard(gameBoard);
				player1->setSymbol('X');
				player2->setSymbol('O');
				gameLogic(gameBoard, player1, player2); 
		break;

		//Random AI, with AI going first
		case 4: player1 = new RandomAI();
				player2 = new Human();
				player1->setGameBoard(gameBoard);
				player1->setSymbol('X');
				player2->setSymbol('O');
				gameLogic(gameBoard, player1, player2);
		break;

		// Better AI, with player going first
		case 6: std::cout << "Better AI not implemented yet :(\n";
		break;

		// Better AI, with AI going first
		case 8: std::cout << "Better AI not implemented yet :(\n";
		break; 
	}

}

void twoPlayerGame(Board* gameBoard)
{
	Player* player1 = new Human();
	player1->setSymbol('X');
	Player* player2 = new Human();
	player2->setSymbol('O');
	gameLogic(gameBoard, player1, player2);
	/*
	while(!gameBoard->gameOver())
	{
		std::cout << "Player 1's turn\n";
		while(!gameBoard->setSpace(player1->move(), player1->getSymbol()))
		{
			std::cout << "That was an invalid move. Please move again\n";
		}
		gameBoard->displayBoard();
		if(gameBoard->gameOver()) break; //If the game has been won or there was a tie, break;
		std::cout << "Player 2's turn\n";
		while(!gameBoard->setSpace(player2->move(), player2->getSymbol()))
		{
			std::cout << "That was an invalid move. Please move again\n";
		}
		gameBoard->displayBoard();
	}*/
}

void game(Board* gameBoard)
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


int main()
{
	Board* gameBoard = new Board();
	game(gameBoard);

	return 0;
}