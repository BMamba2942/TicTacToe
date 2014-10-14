#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printBoard(int**&, char**&);   // Prints the board to the console
bool move(int**&);                  // Processes the moves
int menu();                         // Prints the menu to the user
bool canWin(int);                   // Determines whether "AI" can win
int moveCount(int**);               // Counts how many moves are possible 
int** consecutive(int**, int, int); // Determines row/column of consecutive 
                                    // spaces
int** spacesAvailable(int**);       // Determines what spaces are empty
bool winCheck(int**, int, int);     // Checks if the game has been won
bool validMove(int**, int, int);    // Checks if the space is already occupied
bool validSpace(int, int);          // Input validation
bool aiMove(int**&);                // AI calculates its move
bool block(int**);                  // Determines whether AI needs to block
int* winMove(int**);
int* blockMove(int**);
bool randMove(int**);               // Random move


int turn = 1;

int main()
{
   srand(time(NULL));
   int** board = new int*[3]; //Used in calculation
   for(int i = 0; i < 3; ++i)
      board[i] = new int[3];
   char** view = new char*[3]; //Used in printing
   for(int i = 0; i < 3; ++i)
      view[i] = new char[3];
   bool win = false;
   for(int i = 0; i < 3; ++i)
   {
      for(int j = 0; j < 3; ++j)
         board[i][j] = 0;
   }
   char cont = 'N';
   do {
      srand(time(NULL));
      board = new int*[3]; //Used in calculation
      for(int i = 0; i < 3; ++i)
         board[i] = new int[3];
      view = new char*[3]; //Used in printing
      for(int i = 0; i < 3; ++i)
         view[i] = new char[3];
      bool win = false;
      for(int i = 0; i < 3; ++i)
      {
         for(int j = 0; j < 3; ++j)
            board[i][j] = 0;
      }

      int aiWins = 0, 
	      randWins = 0,
	      ties = 0,
	      games = 0,
	      decision = 0,
	      first = 0;

      switch(menu())
      {
         case 1:   
         while(moveCount(board) != 0 && !win)
         {
            switch(turn)
            {
               case 1: // Players turn
                  if(move(board))
                     win = true;
                  printBoard(board, view);
			      cout << endl << endl;
               break;
               case -1: // AI's turn
                  if(aiMove(board))
                     win = true;
                  printBoard(board, view);
			   
               break;
            }
         }
   
         if(win)
         {
            switch(turn)
            {
               case 1: cout << "The O player has won!\n";
               break;

               case -1: cout << "The X player has won!\n";
               break;
            }
         }
         else
            cout << "You've tied...\n";
         break;

         case 2:
         while(moveCount(board) != 0 && !win)
         {
            if(move(board))
               win = true;
            printBoard(board, view);
         }
   
         if(win)
         {
            switch(turn)
            {
               case 1: cout << "The O player has won!\n";
               break;

               case -1: cout << "The X player has won!\n";
               break;
            }
         }
         else
            cout << "You've tied...\n";
         break;
 
         case 3:
	     cout << "Shall they speed run or do you wish to watch?\n";
	     cout << "1. Speed Run\n2. Watch\n";
	     cout << "(If you chose a lot of games, I highly recommend you speed run)\n";
	     cin >> decision;
	     cout << "How many games shall they play?\n";
	     cin >> games;
	     cout << "Who shall go first?\n";
	     cout << "1. AI\n2. Random \"AI\"\n";
	     cin >> first;
	     switch(decision)
	     {
	     case 1:
	         for(int i = 0; i < games; i++)
		     {
	           while(moveCount(board) != 0 && !win)
		       {
				  switch(first)
				  {
                  case 1: 
				      switch(turn)
				      {
				      case 1:
					      if(aiMove(board))
					         win = true;
				      break;
				      case -1:
					      if(randMove(board))
					   	     win = true;
				      break;
				      }
				      break;
				   case 2:
				      switch(turn)
				      {
				      case 1:
					      if(randMove(board))
					         win = true;
				      break;
				      case -1:
					      if(aiMove(board))
						      win = true;
				      break;
				      }
				      break;
				   }
				
			   }
			   if(win)
			   {
			      switch(first)
			      {
			      case 1:
			         switch(turn)
			         {
			         case 1: randWins++;
			         break;
			         case -1: aiWins++;
			         break;
				     }
			      break;
			      case 2:
				      switch(turn)
			          {
			          case 1: aiWins++;
			          break;
			          case -1: randWins++;
			          break;
				      }
			          break;
			     }
			}
			else
				ties++;

			for(int i = 0; i < 3; ++i)
            {
               for(int j = 0; j < 3; ++j)
                  board[i][j] = 0;
            }

			for(int i = 0; i < 3; ++i)
            {
               for(int j = 0; j < 3; ++j)
                  view[i][j] = ' ';
            }
			win = false;
			turn = 1;
			
		 }
		 cout << "The AI won " << aiWins << " times.\n";
		 cout << "The random \"AI\" won " << randWins << " times.\n";
		 cout << "There were " << ties << " ties\n";
	  break;
	  case 2:
		  for(int i = 0; i < games; i++)
		  {
	        while(moveCount(board) != 0 && !win)
			{
				switch(turn)
				{
				case 1:
					if(randMove(board))
					   win = true;
					printBoard(board, view);
					cout << endl;
				break;
				case -1:
					if(aiMove(board))
						win = true;
					printBoard(board, view);
					cout << endl;
	
				break;
				}
				
			}
			if(win)
			{
			   switch(turn)
			   {
			   case 1: aiWins++;
			   break;
			   case -1: randWins++;
			   break;
			   }
			}
			else
				ties++;

			for(int i = 0; i < 3; ++i)
            {
               for(int j = 0; j < 3; ++j)
                  board[i][j] = 0;
            }

			for(int i = 0; i < 3; ++i)
            {
               for(int j = 0; j < 3; ++j)
                  view[i][j] = ' ';
            }
			win = false;
			turn = 1;
			
		 }
		 cout << "The AI won " << aiWins << " times.\n";
		 cout << "The random \"AI\" won " << randWins << " times.\n";
		 cout << "There were " << ties << " ties\n";
	  break;
	  }
	  
   }
   cout << "Would you like to run it again?(Y/N)\n";
   cin >> cont; 
   while(cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N')
   {
      cout << "That is not correct. Please enter in either Y or N.\n";
      cin >> cont;
   }
   turn = 1;
   }while(cont == 'Y' || cont == 'y');

   system("pause");
   for(int i = 0; i < 3; ++i)
   {
	   delete [] board[i];
	   delete [] view[i];
   }
   delete [] board;
   delete [] view;
   return 0;
}
void printBoard(int**& board, char**& view)
{
   for(int i = 0; i < 3; ++i)
   {
      for(int j = 0; j < 3; ++j)
      {
         switch(board[i][j])
         {
            case 1: view[i][j] = 'X';
            break;
         
            case -1: view[i][j] = 'O';
            break;
 
            case 0: view[i][j] = ' ';
            break;
         }
      }
   }

   for(int i = 0; i < 3; ++i)
   {
      for(int j = 0; j < 3; ++j)
      {
         cout << view[i][j] << " |";
      }
      cout << endl;
   }

}

bool move(int**& data) 
{
   int loc1, loc2;

   cout << "Where would you like to move?\n";

   cout << "1. Top Row\n2. Middle Row\n3. Bottom Row\n";
   cin >> loc1;

   cout << "1. Left Column\n 2. Middle Column\n 3. Right Column\n";
   cin >> loc2;
   if(validSpace(loc1 - 1, loc2 - 1))
      if(validMove(data, loc1-1, loc2-1))
      {
      data[loc1-1][loc2-1] = turn;
      turn = turn * -1;
      return winCheck(data, loc1-1, loc2-1);
      }
      else
         cout << "Space occupied! Please select another space: \n";
   else
      cout << "That is not a valid space. Please select a valid space.\n";
   return false;
}
int menu()
{
   int game;
   cout << "What kind of game would you like it to be?\n";
   cout << "1. 1 player(vs AI)\n";
   cout << "2. 2 player(vs human)\n";
   cout << "3. AI vs Randomized moves\n";
   cin >> game;
   
   return game;
}

bool canWin(int** board)
{
    int count = 0, empty= 0;
    
    // Check for 3 consecutive X's in horizontal rows
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[i][j] == turn)
             count++;
          if(board[i][j] == 0)
             empty++;
       }
       if(count == 2 && empty == 1)
          return true;
      
       count = 0;
       empty = 0;
    }

    // Check for 3 consecutive X's in vertical columns
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[j][i] == turn)
             count++;
          if(board[j][i] == 0)
             empty++;
       }
       if(count == 2 && empty == 1)
          return true;
          
       count = 0;
       empty = 0;
    }

    // Check for 3 consecutive diagonal X's
    for(int i = 0; i < 3; ++i)
    {
       if(board[i][i] == turn)
          count++;
       if(board[i][i] == 0)
          empty++;
    }
    if(count == 2 && empty ==1)
       return true;
    
    count = 0;
    empty = 0;

    int j = 0;    
    for(int i = 3; i > 0; --i)
    {
       if(board[i-1][j] == turn)
          count++;
       if(board[i-1][j++] == 0)
          empty++;
    }
    if(count == 2 && empty == 1)
       return true;
    count = 0;
    empty = 0;
    return false;
}

int moveCount(int** board)
{
   int count = 9;
   for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
         if(board[i][j] != 0)
            --count;

   return count;
}

int** spacesAvailable(int** board)
{
   int spaceRow = 0, spaceColumn = 0;
   int** spaces = new int*[9]; 
   for(int i = 0; i < 9; ++i)
      spaces[i] = new int[2];

   for(int i = 0; i < 3; ++i)
   {
      for(int j = 0; j < 3; ++j)
      {
         if(board[i][j] == 0)
         {
            spaces[spaceRow][spaceColumn] = i;
			spaceColumn++;
            spaces[spaceRow][spaceColumn] = j;
			spaceRow++;
         } 
		 spaceColumn = 0;
      }
   }

   return spaces;
}

bool winCheck(int** board, int row, int column)
{
    int count = 0;
    
    // Check for 3 consecutive X's in horizontal rows
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[i][j] == 1)
             count++;
       }
       if(count == 3)
          return true;
       else
          count = 0;
    }

    // Check for 3 consecutive X's in vertical columns
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[j][i] == 1)
             count++;
       }
       if(count == 3)
          return true;
       else
          count = 0;
    }

    // Check for 3 consecutive diagonal X's
    for(int i = 0; i < 3; ++i)
    {
       if(board[i][i] == 1)
          count++;
    }
    if(count == 3)
       return true;
    else
       count = 0;
    int j = 0;    
    for(int i = 3; i > 0; --i)
    {
       if(board[i-1][j++] == 1)
          count++;
    }
    if(count == 3)
       return true;
    else
       count = 0;
    // Check for 3 consecutive O's in horizontal rows
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[i][j] == -1)
             count++;
       }
       if(count == 3)
          return true;
       else
          count = 0;
    }

    // Check for 3 consecutive O's in vertical columns
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[j][i] == -1)
             count++;
       }
       if(count == 3)
          return true;
       else
          count = 0;
    }

    // Check for 3 consecutive diagonal O's
    for(int i = 0; i < 3; ++i)
    {
       if(board[i][i] == -1)
          count++;
    }
    if(count == 3)
       return true;
    else
       count = 0;
    j = 0;
    for(int i = 3; i > 0; --i)
    {
       if(board[i-1][j++] == -1)
          count++;
    }
    if(count == 3)
       return true;
    else
       count = 0;
   return false;
}
bool validMove(int** board, int row, int column)
{
   return (board[row][column] == 0) ? true : false;
}

bool validSpace(int row, int column)
{
   return (row <= 2 && row >= 0 && column <= 2 && column >= 0);
}

bool aiMove(int**& board)
{
   //srand(time(NULL));
   int** spaces = new int*[9];
   for(int i = 0; i < 9; i++)
      spaces[i] = new int[2];
   int* temp = new int[2];
   int row;
   int column;
   if(moveCount(board) > 7) // was 7
   {
      switch(rand() % 4) // rand() % 4
      {
         case 0:
         if(board[0][0] == 0)
         {
            board[0][0] = turn;
            row = 0;
            column = 0;
            break;
         }
         case 1:
         if(board[2][0] == 0)
         {
            board[2][0] = turn;
            row = 2;
            column = 0;
            break;
         }
         case 2:
         if(board[2][2] == 0)
         {
            board[2][2] = turn;
            row = 2;
            column = 2;
            break;
         }
         case 3:
         if(board[0][2] == 0)
         {
            board[0][2] = turn;
            row = 0;
            column = 2;
            break;
         }
      }
   }
   else
   {
      if(canWin(board))
      {
         temp = winMove(board);
         board[temp[0]][temp[1]] = turn;
      }
      else if(block(board))
      {
         temp = blockMove(board);
         board[temp[0]][temp[1]] = turn;
      }
      else
      {
         spaces = spacesAvailable(board);
         temp = spaces[rand() % moveCount(board)];
         if(validMove(board, temp[0], temp[1]))
            board[temp[0]][temp[1]] = turn;
      }
   }
   turn = turn * -1;
   return winCheck(board, row, column);
}

bool block(int** board)
{
   int count = 0, empty= 0;
    
    // Check for 3 consecutive X's in horizontal rows
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[i][j] == (turn * -1))
             count++;
          if(board[i][j] == 0)
             empty++;
       }
       if(count == 2 && empty == 1)
          return true;
      
       count = 0;
       empty = 0;
    }

    // Check for 3 consecutive X's in vertical columns
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[j][i] == (turn * -1))
             count++;
          if(board[j][i] == 0)
             empty++;
       }
       if(count == 2 && empty == 1)
          return true;
          
       count = 0;
       empty = 0;
    }

    // Check for 3 consecutive diagonal X's
    for(int i = 0; i < 3; ++i)
    {
       if(board[i][i] == (turn * -1))
          count++;
       if(board[i][i] == 0)
          empty++;
    }
    if(count == 2 && empty ==1)
       return true;
    
    count = 0;
    empty = 0;

    int j = 0;    
    for(int i = 3; i > 0; --i)
    {
       if(board[i-1][j] == (turn * -1))
          count++;
       if(board[i-1][j++] == 0)
          empty++;
    }
    if(count == 2 && empty == 1)
       return true;
    count = 0;
    empty = 0;
    return false;
}

int* winMove(int** board)
{
   int* winCoords;
   winCoords = new int[2];
   int count = 0, empty = 0;
    
    // Check for move to make 3 consecutive X's in horizontal rows
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[i][j] == turn) // If it's AI's  mark
             count++;
          if(board[i][j] == 0)
             empty++;
          if(count == 2 && empty == 1)
          {
             for(int k = 0; k < 3; ++k)
             {
                if(board[i][k] == 0)
                {
                   winCoords[0] = i;
                   winCoords[1] = k;
                   return winCoords;
                }
             }
          }
       }
       count = 0;
       empty = 0;
    }


    // Check for 3 consecutive X's in vertical columns
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[j][i] == turn) // If it's AI's  mark
             count++;
          if(board[j][i] == 0)
             empty++;
          if(count == 2 && empty == 1)
          {
             for(int k = 0; k < 3; ++k)
             {
                if(board[k][i] == 0)
                {
                   winCoords[0] = k;
                   winCoords[1] = i;
                   return winCoords;
                }
             }
          }
       }
       count = 0;
       empty = 0;
    }

    for(int i = 0; i < 3; ++i)
    {
       if(board[i][i] == turn)
          count++;
       if(board[i][i] == 0)
          empty++; 
       if(count == 2 && empty == 1)
       {
          for(int k = 0; k < 3; ++k)
             if(board[k][k] == 0)
             {
                winCoords[0] = k;
                winCoords[1] = k;
                return winCoords;
             }
       }
    }
    count = 0;
    empty = 0;
    int j = 0;    
    for(int i = 3; i > 0; --i)
    {
       if(board[i-1][j] == turn)
          count++;
       if(board[i-1][j++] == 0)
          empty++;
       if(count == 2 && empty == 1)
       { 
          j = 0;
          for(int k = 3; k > 0; --k)
          {
             if(board[k-1][j] == 0)
             {
                winCoords[0] = k-1;
                winCoords[1] = j;
                return winCoords;
             }
             j++;  
          }
       }
    }

    return winCoords;

}

int* blockMove(int** board)
{
    int* blockCoords = new int[2];
    int count = 0, empty = 0;
    
    // Check for 3 consecutive X's in horizontal rows
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[i][j] == (turn * -1)) // If it's opponents mark
             count++;
          else if(board[i][j] == 0)
             empty++;
          if(count == 2 && empty == 1)
          {
             for(int k = 0; k < 3; ++k)
             {
                if(board[i][k] == 0)
                {
                   blockCoords[0] = i;
                   blockCoords[1] = k;
                   return blockCoords;
                }
             }
          }
       }
       count = 0;
       empty = 0;
    }

    // Check for 3 consecutive X's in vertical columns
    for(int i = 0; i < 3; ++i)
    {
       for(int j = 0; j < 3; j++)
       {
          if(board[j][i] == (turn * -1))
             count++;
          if(board[j][i] == 0)
             empty++;
          if(count == 2 && empty == 1)
          {    
             for(int k = 0; k < 3; k++)
                if(board[k][i] == 0)
                {
                   blockCoords[0] = k;
                   blockCoords[1] = i;
                   return blockCoords;
                }
          }
       }
       count = 0;
       empty = 0;
    }
    // Check for 3 consecutive diagonal X's
    for(int i = 0; i < 3; ++i)
    {
       if(board[i][i] == (turn * -1))
          count++;
       if(board[i][i] == 0)
          empty++; 
       if(count == 2 && empty == 1)
       {
          for(int k = 0; k < 3; ++k)
             if(board[k][k] == 0)
             {
                blockCoords[0] = k;
                blockCoords[1] = k;
                return blockCoords;
             }
       }
       //count = 0;
       //empty = 0;
    }
    count = 0;
    empty = 0;;
    int j = 0;    
    for(int i = 3; i > 0; --i)
    {
       if(board[i-1][j] == (turn * -1))
          count++;
       if(board[i-1][j++] == 0)
          empty++;
       if(count == 2 && empty == 1)
       { 
          j = 0;
          for(int k = 3; k > 0; --k)
          {
             if(board[k-1][j] == 0)
             {
                blockCoords[0] = k-1;
                blockCoords[1] = j;
                return blockCoords;
             }
             j++;  
          }
       }
    }

   return blockCoords;
}

bool randMove(int** board)
{
   int** spaces = new int*[9];
   for(int i = 0; i < 9; i++)
	   spaces[i] = new int[2];

   int* moveTemp = new int[2];

   spaces = spacesAvailable(board);
   //srand(time(NULL));

   moveTemp = spaces[rand() % moveCount(board)];

   board[moveTemp[0]][moveTemp[1]] = turn;
   turn = turn * -1;

   return winCheck(board, moveTemp[0], moveTemp[1]);
}
