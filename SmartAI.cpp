#include "SmartAI.h"

//#define DEBUG // Uncomment this to enable debugging output
//Debugging includes here
#ifdef DEBUG
   #include <iostream>
#endif


int SmartAI::move()
{
	gameBoard = getGameBoard();
	char oppSymbol = (this->symbol == 'X') ? 'O' : 'X';
	int* spacesAvailable = gameBoard->getSpaces();
	int winSpace = blockOrWin(this->symbol);
	int blockedSpace = blockOrWin(oppSymbol);
	if(winSpace != -1)
		return winSpace;
	else if(blockedSpace != -1)
	{
		return blockedSpace;
	}
	else
		return spacesAvailable[1+(rand() % spacesAvailable[0])];
};

int SmartAI::blockOrWin(char checkSymbol)
{
	int* spacesToCheck = gameBoard->getSpaces();
	int count = 0;
	for(int i = 1; i < spacesToCheck[0]+1; ++i)
	{
		#ifdef DEBUG
		  std::cout << "Space: " << spacesToCheck[i] << std::endl;
		#endif
		switch(spacesToCheck[i])
		{
			case 0:
			if((gameBoard->getSpaceSymbol(1) == checkSymbol && gameBoard->getSpaceSymbol(2) == checkSymbol)
				||(gameBoard->getSpaceSymbol(3) == checkSymbol && gameBoard->getSpaceSymbol(6) == checkSymbol)
				||(gameBoard->getSpaceSymbol(4) == checkSymbol && gameBoard->getSpaceSymbol(8) == checkSymbol))
			{
				return 0;
			}
			break;
			case 1:
			if((gameBoard->getSpaceSymbol(0) == checkSymbol && gameBoard->getSpaceSymbol(2) == checkSymbol)
				||(gameBoard->getSpaceSymbol(4) == checkSymbol && gameBoard->getSpaceSymbol(7) == checkSymbol))
			{
				return 1;
			}
			break;
			case 2:
			if((gameBoard->getSpaceSymbol(0) == checkSymbol && gameBoard->getSpaceSymbol(1) == checkSymbol)
				||(gameBoard->getSpaceSymbol(4) == checkSymbol && gameBoard->getSpaceSymbol(6) == checkSymbol)
				||(gameBoard->getSpaceSymbol(5) == checkSymbol && gameBoard->getSpaceSymbol(8) == checkSymbol))
			{
				return 2;
			}
			break;
			case 3:
			if((gameBoard->getSpaceSymbol(0) == checkSymbol && gameBoard->getSpaceSymbol(6) == checkSymbol)
				||(gameBoard->getSpaceSymbol(4) == checkSymbol && gameBoard->getSpaceSymbol(5) == checkSymbol))
			{
				return 3;
			}
			break;
			case 4:
			if((gameBoard->getSpaceSymbol(0) == checkSymbol && gameBoard->getSpaceSymbol(8) == checkSymbol)
				||(gameBoard->getSpaceSymbol(1) == checkSymbol && gameBoard->getSpaceSymbol(7) == checkSymbol)
				||(gameBoard->getSpaceSymbol(2) == checkSymbol && gameBoard->getSpaceSymbol(6) == checkSymbol)
				||(gameBoard->getSpaceSymbol(3) == checkSymbol && gameBoard->getSpaceSymbol(5) == checkSymbol))
			{
				return 4;
			}
			break;
			case 5:
			if((gameBoard->getSpaceSymbol(2) == checkSymbol && gameBoard->getSpaceSymbol(8) == checkSymbol)
				||(gameBoard->getSpaceSymbol(3) == checkSymbol && gameBoard->getSpaceSymbol(4) == checkSymbol))
			{
				return 5;
			}
			break;
			case 6:
			if((gameBoard->getSpaceSymbol(0) == checkSymbol && gameBoard->getSpaceSymbol(3) == checkSymbol)
				||(gameBoard->getSpaceSymbol(2) == checkSymbol && gameBoard->getSpaceSymbol(4) == checkSymbol)
				||(gameBoard->getSpaceSymbol(7) == checkSymbol && gameBoard->getSpaceSymbol(8) == checkSymbol))
			{
				return 6;
			}
			break;
			case 7:
			if((gameBoard->getSpaceSymbol(1) == checkSymbol && gameBoard->getSpaceSymbol(4) == checkSymbol)
				||(gameBoard->getSpaceSymbol(6) == checkSymbol && gameBoard->getSpaceSymbol(8) == checkSymbol))
			{
				return 7;
			}
			break;
			case 8:
			if((gameBoard->getSpaceSymbol(0) == checkSymbol && gameBoard->getSpaceSymbol(4) == checkSymbol)
				||(gameBoard->getSpaceSymbol(2) == checkSymbol && gameBoard->getSpaceSymbol(5) == checkSymbol)
				||(gameBoard->getSpaceSymbol(6) == checkSymbol && gameBoard->getSpaceSymbol(7) == checkSymbol))
			{
				return 8;
			}
			break;

		}
	}
	#ifdef DEBUG
	  std::cout << "Nothing found, returning -1\n";
	  std::cout << checkSymbol << std::endl;
	#endif
	return -1;
}