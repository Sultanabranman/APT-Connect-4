/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : CHRISTOPHER ROBERT SALTER
* Student Number   : s3334875
* Course Code      : COSC1076
* Program Code     : BP162
* Start up code provided by Paul Miller
***********************************************************************/
#include "scoreboard.h"

/**
 * @param board the scoreboard to initialise
 **/
void init_scoreboard(scoreboard board)
{
	/* loop counter */
	int i;
	
	/* creates an empty score struct initialised to safe values */
	score empty_score;
	char* empty_name = "";
	
	strcpy(empty_score.name, empty_name);	 
	empty_score.thiscolor = C_EMPTY;
	empty_score.counters = NOCOUNTERS;
	empty_score.type = HUMAN;
	
	/* fills scoreboard with empty structs */
	for(i = 0; i < SCOREBOARDSIZE; i++)
	{
		board[i] = empty_score;
	}
	
	return;
}

/** For this requirement, you will need to display the scores in the
 * order they are scored in the scoreboard array. 
 *
 * The display should look as follows: 
 * Player               |Score
 * --------------------------------------------- 
 * Barney               |17 
 * Magi                 |15 
 * Red                  |10 
 * Computer             |8 
 * Computer             |7 
 * Computer             |6 
 * Paul                 |4 
 * Fred                 |4 
 * Muaddib              |4
 * Zafiqa               |4
 * 
 * @param board the scoreboard to display
 **/
void display_scores(const scoreboard board)
{
	/* loop counter */	
	int i;
	
	char player[] = "Player";
    char score[] = "Score";
	
	printf(" %-20s | %-20s \n", player, score);
	printf("---------------------------------------------\n");
	
	for(i=0; i < SCOREBOARDSIZE; i++)
	{
		/* Checks if scoreboard position is empty */
		if((*board[i].name) == '\0')
		{
			return;
		}
		/* Prints player name and score to console */
		else
		{
			printf(" %-20s | %-20d \n", board[i].name, board[i].counters);
		}
	}
	
	return;
	
}

/** When the game ends, you need to return the appropriate game state
 * back to main. You will then need to insert the winner's score
 * sorted in order by the number of counters that they played in the
 * game. You should only store the top ten scores and so when a new score
 * is entered on a full scoreboard, the lowest score simply drops off the
 * bottom of the board.  
 * 
 * Both scoreboard and score are typedefs (aliases) of other types.
 *
 * Scoreboard is defined as: typedef struct player
 *
 * scoreboard[SCOREBOARDSIZE]; and score is defined as: 
 *
 * typedef struct player score; 
 *
 * In other words, a scoreboard is an array of struct player of
 * SCOREBOARDSIZE (10) and a score is another name of a player struct.
 * This has been done so we can reuse the type and it simplifies the
 * maintenance of the code.
 * 
 * @param board the scoreboard to add the score to @param sc the score
 * to add to the scoreboard
 **/ 
 BOOLEAN add_to_scoreboard(scoreboard board, const score * sc) 
 {
    /* loop counter */
	int i, j;
	 
    if(sc == NULL)
	{
		return FALSE;
	}
	/* Iterates through the scoreboard */
	for(i = 0; i < SCOREBOARDSIZE; i++)
	{
		/* Checks if new score is higher than old score */
		if(sc->counters > board[i].counters)
		{
		   /** Starts at the second last scoreboard position and copies old 
			* score one place down until it reaches position where new score 
			* is to be entered 
		   **/
			for(j = SECONDLASTPOSITION; j >= i; j--)
			{
				board[NEXTSCOREBOARDPOSITION] = board[j];
			}
			/* Places new score into sorted position */
			board[i] = *sc;
			
			return SUCCESS;
		}
	}
	
    return FALSE; 
}
