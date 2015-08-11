/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : CHRISTOPHER ROBERT SALTER
* Student Number   : s3334875
* Course Code      : COSC1076
* Program Code     : BP162
* Start up code provided by Paul Miller
***********************************************************************/
#include "con4.h"

/**
 * @mainpage COSC1076 - Assignment 1 documentation.
 *
 * This is the main html documentation of assignment 1 for COSC1076 -
 * Advanced Programming Techniques for semester 2, 2015. You will find
 * here a description of the functions that you need to implement for
 * your assignment.
 *
 * Please note that this should not be your first stop when starting
 * your assignment. Please read the assignment 1 specifications that
 * are available on blackboard before reading this documentation. The
 * purpose of this documentation is to clarify the actual individual
 * requirements.
 *
 * This site presents you with the documentation for each function
 * that you need to implement broken down by the file that they exist
 * in. Please go to the <b>Files</b> tab and click on the file you wish to
 * get more information about and then click on that file. An
 * explanation of each function implemented in that file will be
 * displayed.
 **/

/**
 * @file con4.c contains the main function which is the entry point into the 
 * application and manages the main memory.
 **/

/**
 * the entry point into the game. You should display the main menu and 
 * respond to user requests.
 *
 * The main menu should look like this: 
 * Welcome to connect 4
 *  \n\--------------------
 * 1. Play Game
 * 2. Display High Scores
 * 3. Quit
 * Please enter your choice:
 *
 * This menu should also be redisplayed when the program returns from 
 * running an option.
 **/
int main(void)
{
    /* the scoreboard for keeping track of winners */
    scoreboard scores;
    /* the two players and a pointer to who won the last game */
    struct player human_player, computer_player, *winner;
	
	/* Pointers to the human and computer structs */
	struct player *p_human_player, *p_computer_player;
	
	/* Assigns the pointers the address of the human and computer structs */
	p_human_player = &human_player;
	p_computer_player = &computer_player;

    /* with each of the comments below, insert the code that performs 
     * this function 
     */

    /* initialise the scoreboard */

    /*display menu and get menu choice until the user chooses to quit */

	while(1)
    {
       switch(menu())
       {
          /*play game*/
           case PLAYGAME:
               {   
			       get_human_player(p_human_player);			   
				   get_computer_player(p_computer_player);
				   play_game(p_human_player, p_computer_player);
                   break;
               }
           /* Display scoreboard*/
           case DISPLAYSCOREBOARD:
               {                   
                   break;
               }
           
           /*Exit Program*/
           case QUIT:
               {
                   puts("\nExiting program....");
                   exit(0);
               }
           default:
               {
                   puts("\nInvalid Input, try again\n");
                   break;
               }
       }

    }	    

    return EXIT_SUCCESS;
}

int menu(void)
{
    int menu_input;

    printf("Welcome to connect 4\n");
	printf("--------------------\n");
    printf("1) Play Game\n");
    printf("2) Display Scoreboard\n");
    printf("3) Quit\n");  
	printf("Please enter your choice: ");

    scanf("%d", &menu_input);
    read_rest_of_line();
	
	printf("\n");

    return menu_input;
}
