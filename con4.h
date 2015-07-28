/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : CHRISTOPHER ROBERT SALTER
* Student Number   : s3334875
* Course Code      : COSC1076
* Program Code     : BP162
* Start up code provided by Paul Miller
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "helpers.h"
#include "scoreboard.h"
#include "player.h"
#include "game.h"
#include "bool.h"
/**
 * @file con4.h simply puts together all the other header files for 
 * inclusion in @ref con4.c
 **/
 
#define PLAYGAME 1
#define DISPLAYSCOREBOARD 2
#define QUIT 3
 
 int menu(void);
