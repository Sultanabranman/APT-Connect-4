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
	
	char player_name[NAMELEN + 1];	
	getPlayerName(player_name);	
	
	strcpy((*human).name, player_name);
	(*human).thiscolor = C_EMPTY;
	(*human).counters = NO_COUNTERS;
	(*human).type = HUMAN;
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
	 strcpy((*computer).name, computer_name);
	 (*computer).thiscolor = C_EMPTY;
	 (*computer).counters = NO_COUNTERS;
	 (*computer).type = COMPUTER;

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
	char user_input[INPUT_LEN];
	
    if((*current).type == HUMAN)
	{
		while(1)
		{
		    printf("Please enter a column in which to drop a token:\n");
		    		
		}
		
	}
	if((*current).type == COMPUTER)
	{
		
	}    
}

void getPlayerName(char* name)
{
	
	char player_name[NAMELEN + 1];	
	char prompt[PROMPT_LENGTH + 1];

	/* Get name of player 1 */
	
	sprintf(prompt, "What is your name? (max %d characters): "
		, NAMELEN);

	getString(player_name, NAMELEN, prompt);
	
	printf("Player name is: '%s'\n\n", player_name);
	
	strcpy(name, player_name);
	
	return;
}	

