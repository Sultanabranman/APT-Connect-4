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
#include "helpers.h"

#ifndef PLAYER_H
#define PLAYER_H
/**
 *  maximum length of a player name in the game
 **/
#define NAMELEN 20
#define PROMPT_LENGTH 80
#define INPUT_LEN 1
#define NO_COUNTERS 0

/* Used to bring in line with array counting */
#define DECREMENTBY1 1

/**
 * defines the type of the player
 **/
enum playertype
{
    /**
     * a computer player
     **/
    COMPUTER,
    /**
     * a human player
     **/
    HUMAN
};

/**
 * the details about a player that need to be kept track of for the game
 **/
struct player
{
    /**
     * the player's name
     **/
    char name[NAMELEN+1];
    /**
     * the color of the token for the player. Note: this is a typedef of 
     * enum @ref cell_contents.
     **/
    color thiscolor;
    /**
     * how many counters does this player have on the board? 
     **/
    unsigned counters;
    /**
     * what type of player is this? A human or a computer? 
     **/
    enum playertype type;
};

/**
 * initialise the human player including getting their name as user input
 **/
 enum input_result get_human_player(struct player *);

/**
 * initialise the computer player's data
 **/
enum input_result get_computer_player(struct player *);

/**
 * this is where the player takes a turn. If they are a computer player, 
 * insert the token in a random column. If they are a human player 
 * ask them which column they wish to drop a token into.
 **/
enum input_result take_turn(struct player *, enum cell_contents[][BOARDWIDTH]);

/** Gets player name **/
void getPlayerName(char*);

/* Gets the player's column choice and validates input */
enum input_result get_player_column(int *column_choice);
#endif
