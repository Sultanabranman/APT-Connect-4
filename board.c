/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : CHRISTOPHER ROBERT SALTER
* Student Number   : s3334875
* Course Code      : COSC1076
* Program Code     : BP162
* Start up code provided by Paul Miller
***********************************************************************/
#include "board.h"
#include "player.h"

/**
 * @file board.c contains implementations of functions related to the game 
 * board.
 **/

/**
 * @param board the board to reset the contents of
 **/
void initialise_board(enum cell_contents board[][BOARDWIDTH])
{
	int i;
	int j;

	for(i=0; i < BOARDHEIGHT; i++)
	{
		for(j=0; j < BOARDWIDTH; j++)
		{
			board[i][j] = C_EMPTY;
		}
	}

	return;
}

/**
 * In this requirement you are required to display the game board. 
 * The game board should be displayed as shown on the first page of the 
 * assignment specification. 
 * @param board the board to display
 **/
void display_board(enum cell_contents board[][BOARDWIDTH])
{
	int i;
	int j;
	
/** displays column number across top of board **/ 
	for(i = MINCOLUMN; i <= BOARDWIDTH; i++)
	{
		
		/** Enters final column number then enters a line underneath 
		*	numbers 
		**/
		if(i == MAXCOLUMN)
		{
			printf(" %d |", i);
			printf("\n---------------------------- \n");
		}
		/** Enters column number **/
		else
		{
			printf(" %d |", i);
		}
	}
	
/** Fills board with approapriate tokens **/
	for(i=0; i< BOARDHEIGHT; i++)
	{
		for (j=0; j <  BOARDWIDTH ; j++)
		{			
			if(board[i][j] == C_EMPTY)
			{
				printf("   |");
			}
			else if(board[i][j] == C_RED)
			{
				printf(" %s |", RED_TOKEN);
			}
			else if(board[i][j] == C_WHITE)
			{
				printf(" %s |", WHITE_TOKEN);
			}
			/** Puts line across bottom of board **/
			if(j == BOARDWIDTH - 1)
			{
			   printf("\n---------------------------- \n");
			}
		}
	} 

	return;
}
 

