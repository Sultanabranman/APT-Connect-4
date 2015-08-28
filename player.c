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
	
	/* prompts user for name and assigns name to struct if valid */
	switch(getPlayerName(human->name))
	{
		/* Input was valid, initialises to safe values */
		case SUCCESS:
		{
			human->thiscolor = C_EMPTY;
			human->counters = NO_COUNTERS;
			human->type = HUMAN;
			return SUCCESS;
			
			break;
		}
		/* Fatal error occured, exits program */
		case FAILURE:
		{
			fprintf(stderr, "Error: player name input failed");
			exit(EXIT_FAILURE);
			break;
		}
		/* returns the user to the menu */
		case RTM:
		{
			printf("Player has quit before they got started!\n");
			return RTM;
			break;
		}
	}		
	
	return FAILURE;
}

/**
 * @param computer the computer player to initialise
 **/
enum input_result get_computer_player(struct player * computer)
{
	int finished = FALSE;
	
	char* computer_name = "Computer";
	
   /** initialise all variables that are part of the struct to sensible 
    * values 
   **/
	strcpy(computer->name, computer_name);
	computer->thiscolor = C_EMPTY;
	computer->counters = NO_COUNTERS;
	computer->type = COMPUTER;
	finished = TRUE;

	/* if struct initialisation succeeded */
	if(finished == TRUE){
		return SUCCESS;
	}
	/* If struct initialisation failed */
	else
	{
		return FAILURE;
	}
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
	int i, finished = FALSE;
	
	/* Logic for Human player's turn */
    if(current->type == HUMAN)
	{	
	    while(TRUE)
		{			
		/* Loop to get valid user column selection */
		do
		{
			printf("Please enter a column in which to drop a token:\n");
			switch(get_player_column(&column_choice))
			{
				/* User entered a valid integer within the range */
				case SUCCESS:
				{
					finished = TRUE;
					break;
				}
				/* User entered an invalid input */
				case FAILURE:
				{
					finished = FALSE;
					break;
				}
				/* Returns the user to the menu */
				case RTM:
				{	
					printf("%s has quit the game!", current->name);
					return RTM;
					break;
				}
			}
		} while(finished != TRUE);
		
		/* Checks if column is full, then if not places player token */
		for (i = BOARDHEIGHT - DECREMENTBY1; i >= TOPOFBOARD; i--)
		{				
		    if(board[i][column_choice] == C_EMPTY)
		    {
				/* Places player's colour token in column */
			    board[i][column_choice] = current->thiscolor;	
				current->counters++;	
			    return SUCCESS;
		    }
			/* returns to get new input if column is full */
		    else if (board[i][column_choice] != C_EMPTY && i == TOPOFBOARD)
		    {
				fprintf(stderr, "Error: Column is full\n");
			    break;
		    }
		}	
		}		
		
	}
	
	/* Logic for computer player's turn */
	else if(current->type == COMPUTER)
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
					current->counters++;
					
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

enum input_result getPlayerName(char* name)
{
	int finished = FALSE;
	char tempString[NAMELEN + EXTRACHARS] = "";		

	/* Get name of player */
	do
	{
		printf("What is your name?\n");
		
		fgets(tempString, NAMELEN + EXTRACHARS, stdin);
		
		if(tempString[1] == '\0')
        {
            return RTM;
        }
		/* A string that doesn't have a newline character is too long */
		else if (tempString[strlen(tempString) - 1] != '\n')
		{
			fprintf(stderr, "Error: Input was too long\n");
			read_rest_of_line();
		}
		else
		{
			finished = TRUE;
		}
	}while (finished != TRUE);
	
	/* Overwrite the \n character with \0 */
	tempString[strlen(tempString)-1] = '\0';
	
    /* Makes result available to calling function */
	strcpy(name, tempString);
	
	return SUCCESS;	
}	

enum input_result get_player_column(int *column_choice)
{
	char user_input[INPUT_LEN + EXTRACHARS];		
	char* stringcheck = NULL;
	
	
	/* Accept input */
	fgets(user_input, INPUT_LEN + EXTRACHARS, stdin);

	/* Checks if user entered a blank input */
	if(user_input[1] == '\0')
    {   		
	    return RTM;
    }
	
	/* A string that doesn't have a newline character is too long */
	else if(user_input[strlen(user_input) - 1] != '\n')
	{
	    fprintf(stderr, "Error: Input was too long\n");
	    read_rest_of_line();
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
				fprintf(stderr, "Error: Invalid column selection\n");
				return FAILURE;
			}
		/* Prints error if characters where found in the input */
		}
	    else
		{
			fprintf(stderr, "Error: Invalid input!\n");
			return FAILURE;
		}		
	}
}