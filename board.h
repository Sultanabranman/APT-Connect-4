/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : CHRISTOPHER ROBERT SALTER
* Student Number   : s3334875
* Course Code      : COSC1076
* Program Code     : BP162
* Start up code provided by Paul Miller
***********************************************************************/
#include <string.h>
#include <stdio.h>
#include "bool.h"

/**
 * @file board.h contains data definitions that relate to the game board.
 **/

#ifndef BOARD_H
#define BOARD_H
/**
 * how many token in a row do we need for a win?
 **/
#define NUM_IN_ROW 4
/**
 * how wide is the board? 
 **/
#define BOARDWIDTH 7
/**
 * how tall is the board? 
 **/
#define BOARDHEIGHT 6

/**
 * the minimum column number in the game
 **/
#define MINCOLUMN 1
/**
 * the maximum column number in the game
 **/
#define MAXCOLUMN BOARDWIDTH

/* the top of the board in the array */
#define TOPOFBOARD 0

/* the bottom of the board in the array */
#define BOTTOMOFBOARD 5

/* the left side of the board in the array */
#define LEFTOFBOARD 0

/* the right side of the board in the array */
#define RIGHTOFBOARD 6

/* how far to the right needs to be checked for a winner */
#define MAX_HORIZONTAL_CHECK 4

/* how far up needs to be checked for a winner */
#define MAX_VERTICAL_CHECK 3

/* how far to the left needs to be checked for a winner */
#define MAX_DIAGONAL_LEFT_CHECK 3


/**
 * defines the possible contents of each cell of the board
 **/
enum cell_contents
{
    /** the cell does not contain a token **/
    C_EMPTY, 
    /** the cell contains a red token **/
    C_RED, 
    /** the cell contains a white token **/
    C_WHITE
};


/**
 * the code used to print a red game token
 **/
#define RED_TOKEN "\x1b[1;31mO\x1b[1;0m"

/**
 * the code used to print a white token
 **/
#define WHITE_TOKEN "\x1b[1;37mO\x1b[1;0m"

/**
 * forward declaration of player struct so that we can refer to it in this 
 * file - we don't want to #include @ref player.h as that would cause circular
 * dependencies.
 **/
struct player;

/**
 * we give cell contents an alias of color as that is what it defines. 
 **/
typedef enum cell_contents color;

/**
 * initialises the board to being an empty board
 **/
void initialise_board(enum cell_contents[][BOARDWIDTH]);

/**
 * displays the current board to the screen
 **/
void display_board(enum cell_contents[][BOARDWIDTH]);

#endif
