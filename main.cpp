#include "Board.h"
#include "RandomAI.h"
#include "SmartAI.h"
#include "Human.h"
#include <iostream>

const int RANDOM_AI_PLAYER_FIRST = 3, RANDOM_AI_PLAYER_SECOND = 4, SMART_AI_PLAYER_FIRST = 6, SMART_AI_PLAYER_SECOND = 8;

int aiTypesPrompt()
{
	int ai1, ai2;
	std::cout << "What AI should player 1 be?\n1. Random AI\n2. Better AI\n";
	std::cin >> ai1;
	while(ai1 != 1 && ai1 != 2)
	{
		std::cout << "Please enter a valid option (1 for Random, 2 for Better AI)\n";
		std::cin >> ai1;
	}

	std::cout << "What AI should player 2 be?\n3. Random AI\n4. Better AI\n";
	std::cin >> ai2;
	while(ai2 != 3 && ai2 != 4)
	{
		std::cout << "Please enter a valid option (3 for Random, 4 for Better AI)\n";
		std::cin >> ai2;
	}

	return ai1 * ai2;
}

void gameLogic(Board* gameBoard, Player* player1, Player* player2, bool showFeedback)
{
	int result;
	int row, column;
	while(gameBoard->getSpacesCount() > 0)
	{
		if(showFeedback) std::cout << "Player 1's turn\n";
		player1->move(row, column); 
		while(!gameBoard->setSpace(row, column, player1->getSymbol()))
		{
			std::cout << "That was an invalid move. Please move again\n";
			if(showFeedback) gameBoard->displayBoard();
			player1->move(row, column);
		}
		if(showFeedback) gameBoard->displayBoard();
		result = gameBoard->gameOver(player1->getSymbol());
		switch(result)
		{
			case 0: if(showFeedback) std::cout << "The game has ended in a tie.\n";
					player1->incrementTies();
					player2->incrementTies();
			break;
			case 1: if(showFeedback) std::cout << "Player 1 has won the game!\n";
					player1->incrementWins();
					player2->incrementLosses();
			break;
		}
		if(result != -1) break; //If the game has been won or there was a tie, break;
		if(showFeedback) std::cout << "Player 2's turn\n";
		player2->move(row, column);
		while(!gameBoard->setSpace(row, column, player2->getSymbol()))
		{
			std::cout << "That was an invalid move. Please move again\n";
			if(showFeedback) gameBoard->displayBoard();
			player2->move(row, column);
		}
		result = gameBoard->gameOver(player2->getSymbol());
		switch(result)
		{
			case 0: if(showFeedback) std::cout << "The game has ended in a tie.\n";
					player1->incrementTies();
					player2->incrementTies();
			break;
			case 1: if(showFeedback) std::cout << "Player 2 has won the game!\n";
					player2->incrementWins();
					player1->incrementLosses();
			break;
		}
		if(showFeedback) gameBoard->displayBoard();
		if(result != -1) break;
	}
}

void aiBattle(Board* gameBoard)
{
	int choice, games;
	Player* player1, *player2;

	std::cout << "What type of AI game should be played?\n";
	std::cout << "1. Simulation (no printing)\n2. Watch (prints board after every move)\n";
	std::cin >> choice;
	while(choice != 1 && choice != 2)
	{
		std::cout << "Please select a valid option (1 for simulation, 2 for watching the games)\n";
		std::cin >> choice;
	}

	switch(choice)
	{
		case 1: std::cout << "How many games would you like to simulate?\n";
				std::cin >> games;
				switch(aiTypesPrompt())
				{
					case RANDOM_AI_PLAYER_FIRST: player1 = new RandomAI(gameBoard, 'X');
							player2 = new RandomAI(gameBoard, 'O');
					break;
					case RANDOM_AI_PLAYER_SECOND: player1 = new RandomAI(gameBoard, 'X');
							player2 = new SmartAI(gameBoard, 'O');
					break;
					case SMART_AI_PLAYER_FIRST: player1 = new SmartAI(gameBoard, 'X');
							player2 = new RandomAI(gameBoard, 'O');
					break;
					case SMART_AI_PLAYER_SECOND: player1 = new SmartAI(gameBoard, 'X');
							player2 = new SmartAI(gameBoard, 'O');
					break;
				}

				for(unsigned int i = 1; i <= games; ++i)
				{
					gameLogic(gameBoard, player1, player2, false);
					gameBoard->clearBoard();
				}
		break;
		case 2: std::cout << "How many games would you like to watch?\n";
				std::cin >> games;
				switch(aiTypesPrompt())
				{
					case RANDOM_AI_PLAYER_FIRST: player1 = new RandomAI(gameBoard, 'X');
							player2 = new RandomAI(gameBoard, 'O');
					break;
					case RANDOM_AI_PLAYER_SECOND: player1 = new RandomAI(gameBoard, 'X');
							player2 = new SmartAI(gameBoard, 'O');
					break;
					case SMART_AI_PLAYER_FIRST: player1 = new SmartAI(gameBoard, 'X');
							player2 = new RandomAI(gameBoard, 'O');
					break;
					case SMART_AI_PLAYER_SECOND: player1 = new SmartAI(gameBoard, 'X');
							player2 = new SmartAI(gameBoard, 'O');
					break;
				}
				for(unsigned int i = 1; i <= games; ++i)
				{
					gameLogic(gameBoard, player1, player2, true);
					gameBoard->clearBoard();
				}
		break;
	}

	std::cout << "Player 1 stats: " << player1->getWins() << " wins, " << player1->getTies() << " ties, " << " and " << player1->getLosses() << " losses\n";
	std::cout << "Player 2 stats: " << player2->getWins() << " wins, " << player2->getTies() << " ties, " << " and " << player2->getLosses() << " losses\n";

	delete player1;
	delete player2;
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
		case RANDOM_AI_PLAYER_FIRST: player1 = new Human('X');
				player2 = new RandomAI(gameBoard, 'O');
				gameLogic(gameBoard, player1, player2, true);
		break;

		//Random AI, with AI going first
		case RANDOM_AI_PLAYER_SECOND: player1 = new RandomAI(gameBoard, 'X');
				player2 = new Human('O');
				gameLogic(gameBoard, player1, player2, true);
		break;

		// Better AI, with player going first
		case SMART_AI_PLAYER_FIRST: player1 = new Human('X');
				player2 = new SmartAI(gameBoard, 'O');
				gameLogic(gameBoard, player1, player2, true);
		break;

		// Better AI, with AI going first
		case SMART_AI_PLAYER_SECOND: player1 = new SmartAI(gameBoard, 'X');
				player2 = new Human('O');
				gameLogic(gameBoard, player1, player2, true);

		break;
	}

	// "Clean up, clean up..."
	delete player1;
	delete player2;

}

void twoPlayerGame(Board* gameBoard)
{
	Player* player1 = new Human('X');
	Player* player2 = new Human('O');
	gameLogic(gameBoard, player1, player2, true);
	delete player1;
	delete player2;
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
	Board gameBoard;
	gameBoard.initBoard();
	game(&gameBoard);
	return 0;
}
