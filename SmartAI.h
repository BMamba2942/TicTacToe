#pragma once
#include "AI.h"
#include <cstdlib>
#include <ctime>

class SmartAI : public AI
{
	public:
		SmartAI(){};
		int move()
		{
			srand(time(NULL));
			gameBoard = getGameBoard();
			int* spacesAvailable = gameBoard->getSpaces();
			int blockedSpace = block();
			if(blockedSpace != -1)
				return blockedSpace;
			else
				return spacesAvailable[1+(rand() % spacesAvailable[0])];
		};
	private:
		int block()
		{
			char oppSymbol = (this->symbol == 'X') ? 'O' : 'X';
			int* spacesToCheck = gameBoard->getSpaces();
			int count = 0;
			for(int i = 1; i < spacesToCheck[0]; ++i)
			{
				switch(spacesToCheck[i])
				{
					case 0:
					if((gameBoard->getSpaceSymbol(1) == oppSymbol && gameBoard->getSpaceSymbol(2) == oppSymbol)
					 ||(gameBoard->getSpaceSymbol(3) == oppSymbol && gameBoard->getSpaceSymbol(6) == oppSymbol)
					 ||(gameBoard->getSpaceSymbol(4) == oppSymbol && gameBoard->getSpaceSymbol(8) == oppSymbol))
					{
						return 0;
					}
					break;
					case 1:
					if((gameBoard->getSpaceSymbol(0) == oppSymbol && gameBoard->getSpaceSymbol(2) == oppSymbol)
					||(gameBoard->getSpaceSymbol(4) == oppSymbol && gameBoard->getSpaceSymbol(7) == oppSymbol))
					{
						return 1;
					}
					break;
					case 2:
					if((gameBoard->getSpaceSymbol(0) == oppSymbol && gameBoard->getSpaceSymbol(1) == oppSymbol)
					||(gameBoard->getSpaceSymbol(4) == oppSymbol && gameBoard->getSpaceSymbol(6) == oppSymbol)
					||(gameBoard->getSpaceSymbol(5) == oppSymbol && gameBoard->getSpaceSymbol(8) == oppSymbol))
					{
						return 2;
					}
					break;
					case 3:
					if((gameBoard->getSpaceSymbol(0) == oppSymbol && gameBoard->getSpaceSymbol(6) == oppSymbol)
					||(gameBoard->getSpaceSymbol(4) == oppSymbol && gameBoard->getSpaceSymbol(5) == oppSymbol))
					{
						return 3;
					}
					break;
					case 4:
					if((gameBoard->getSpaceSymbol(0) == oppSymbol && gameBoard->getSpaceSymbol(8) == oppSymbol)
					||(gameBoard->getSpaceSymbol(1) == oppSymbol && gameBoard->getSpaceSymbol(7) == oppSymbol)
					||(gameBoard->getSpaceSymbol(2) == oppSymbol && gameBoard->getSpaceSymbol(6) == oppSymbol)
					||(gameBoard->getSpaceSymbol(3) == oppSymbol && gameBoard->getSpaceSymbol(5) == oppSymbol))
					{
						return 4;
					}
					break;
					case 5:
					if((gameBoard->getSpaceSymbol(2) == oppSymbol && gameBoard->getSpaceSymbol(8) == oppSymbol)
					||(gameBoard->getSpaceSymbol(3) == oppSymbol && gameBoard->getSpaceSymbol(4) == oppSymbol))
					{
						return 5;
					}
					break;
					case 6:
					if((gameBoard->getSpaceSymbol(0) == oppSymbol && gameBoard->getSpaceSymbol(3) == oppSymbol)
					||(gameBoard->getSpaceSymbol(2) == oppSymbol && gameBoard->getSpaceSymbol(4) == oppSymbol)
					||(gameBoard->getSpaceSymbol(7) == oppSymbol && gameBoard->getSpaceSymbol(8) == oppSymbol))
					{
						return 6;
					}
					break;
					case 7:
					if((gameBoard->getSpaceSymbol(1) == oppSymbol && gameBoard->getSpaceSymbol(4) == oppSymbol)
					||(gameBoard->getSpaceSymbol(6) == oppSymbol && gameBoard->getSpaceSymbol(8) == oppSymbol))
					{
						return 7;
					}
					break;
					case 8:
					if((gameBoard->getSpaceSymbol(0) == oppSymbol && gameBoard->getSpaceSymbol(4) == oppSymbol)
					||(gameBoard->getSpaceSymbol(2) == oppSymbol && gameBoard->getSpaceSymbol(5) == oppSymbol)
					||(gameBoard->getSpaceSymbol(6) == oppSymbol && gameBoard->getSpaceSymbol(7) == oppSymbol))
					{
						return 8;
					}
					break;

				}
			}
			return -1;
		}
};
