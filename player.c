/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : CHRISTOPHER ROBERT SALTER
* Student Number   : s3334875
* Course Code      : COSC1076
* Program Code     : BP162
* Start up code provided by Paul Miller
***********************************************************************/
#include "player.h"

/**
 * @param human the human player to initialise
 **/
enum input_result get_human_player(struct player * human)
{
    /* placeholder return value. You should prompt the user 
     * for their name and then initialise all other values in the
     * player struct to sensible values.
     */
	
	char player_name[NAMELEN + EXTRACHARS];	
	getPlayerName(player_name);	
	
	strcpy(human->name, player_name);
	human->thiscolor = C_EMPTY;
	human->counters = NO_COUNTERS;
	human->type = HUMAN;
    return SUCCESS;
}

/**
 * @param computer the computer player to initialise
 **/
enum input_result get_computer_player(struct player * computer)
{
	char* computer_name = "COMPUTER";
    /* initialise all variables that are part of the struct to sensible 
     * values */
	 strcpy(computer->name, computer_name);
	 computer->thiscolor = C_EMPTY;
	 computer->counters = NO_COUNTERS;
	 computer->type = COMPUTER;

    return SUCCESS;
}

/**
 * In this requirement, you need to handle the taking of a turn - either
 * of a human or a computer player.
 *
 * For the human player, you will need to allow the user to enter the 
 * column they wish to place a token in. You will need to validate what 
 * the user enters, then place a token correctly in that column so that
 * it occupies the cell closest to the bottom of the board array for that 
 * column.
 *
 * For the computer player, you will need to randomly generate a column 
 * number to place a token in and if that column is full, generate a 
 * different column number until a column number with some free space has 
 * been found.
 *
 * @param current the current player
 * @param board the game board that we will attempt to insert a token into
 * @return enum @ref input_result indicating the state of user input (in 
 * case this run involved user input
 **/
enum input_result take_turn(struct player * current,
        enum cell_contents board[][BOARDWIDTH])
{	
	int column_choice;
	
	/* Loop counter */
	int i;
	
	/* Logic for Human player's turn */
    if((*current).type == HUMAN)
	{	
	    while(TRUE)
		{			
		
		/* Loop to get valid user column selection */
		do
		{
			printf("Please enter a column in which to drop a token:\n");
		} while(get_player_column(&column_choice) != SUCCESS);
		
		/* Checks if column is full, then if not places player token */
		for (i = BOARDHEIGHT - DECREMENTBY1; i >= TOPOFBOARD; i--)
		{				
		    if(board[i][column_choice] == C_EMPTY)
		    {
				/* Places player's colour token in column */
			    board[i][column_choice] = current->thiscolor;	
					
			    return SUCCESS;
		    }
			/* returns to get new input if column is full */
		    else if (board[i][column_choice] != C_EMPTY && i == TOPOFBOARD)
		    {
				fprintf(stderr, "Error:Column is full\n");
			    break;
		    }
		}	
		}		
		
	}
	
	/* Logic for computer player's turn */
	else if((*current).type == COMPUTER)
	{
		int column_choice;
		
		/* loop counter */
		int i;		
		
		/* Loops until valid choice is made */
		while(TRUE)
		{
			/* chooses a random column */
		    column_choice = rand() %MAXCOLUMN;
		
			/* Checks if column is full, then if not places computer token */
		    for (i = BOARDHEIGHT - DECREMENTBY1; i >= TOPOFBOARD; i--)
		    {
			    if(board[i][column_choice] == C_EMPTY)
			    {
					/* Places computer's colour token in column */
				    board[i][column_choice] = current->thiscolor;	
					
				    return SUCCESS;
			    }
				/** Checks if the top of the column is full, then if it is 
				  * returns to choose a new column 
				 **/
			    else if (board[i][column_choice] != C_EMPTY && i == TOPOFBOARD)
			    {
				    break;
			    }
		    }
		}		
	}
	
	/* Forces program to close due to player type assignment failure */
	fprintf(stderr, "Error: Failure with player type assignment\n");
	exit(EXIT_FAILURE);	
	return FAILURE;
}

void getPlayerName(char* name)
{
	
	char player_name[NAMELEN + EXTRACHARS];	
	char prompt[PROMPT_LENGTH + EXTRACHARS];

	/* Get name of player */
	
	sprintf(prompt, "What is your name? (max %d characters):\n"
		, NAMELEN);

	getString(player_name, NAMELEN, prompt);
	
	printf("Player name is: '%s'\n\n", player_name);
	
	strcpy(name, player_name);
	
	return;
}	

enum input_result get_player_column(int *column_choice)
{
	char user_input[INPUT_LEN + EXTRACHARS];		
	char* stringcheck = NULL;
	
	
	/* Accept input */
	fgets(user_input, INPUT_LEN + EXTRACHARS, stdin);

	/* A string that doesn't have a newline character is too long */
	if (user_input[strlen(user_input) - 1] != '\n')
	{
	    printf("Input was too long\n");
	    read_rest_of_line();
		return FAILURE;
	}
	
	/* Checks if user entered a blank input */
	else if(user_input[1] == '\0')
    {
        printf("\nYou must select a column\n");
	    return FAILURE;
    }
	else
	{
		/* Converts user input into a long int */
	    *column_choice = strtol(user_input, &stringcheck, BASE10);
		
		/* Checks if there is any character after integer input */
		if(*stringcheck == '\n')
		{
			/* Checks if the column choice is within the board boundaries */
			if(*column_choice >= MINCOLUMN && *column_choice <= MAXCOLUMN)
	        {		
				*column_choice -= DECREMENTBY1;
			    return SUCCESS;
			}
			/* Prints error if selection is outside board boundaries */
			else
			{
				printf("Invalid column selection");
				return FAILURE;
			}
		/* Prints error if characters where found in the input */
		}
	    else
		{
			printf("Invalid input!\n");
			return FAILURE;
		}
			
	    	
	}
}

	

			
	


