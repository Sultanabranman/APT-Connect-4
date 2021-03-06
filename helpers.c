/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : CHRISTOPHER ROBERT SALTER
* Student Number   : s3334875
* Course Code      : COSC1076
* Program Code     : BP162
* Start up code provided by Paul Miller
***********************************************************************/
#include "helpers.h"

/**
 * @file helpers.c contains various functions that help in the
 * implementation of the program. You should put functions you create
 * here unless they logically belong to another module (such as
 * player, board or game
 **/

void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch!=EOF && ch != '\n')
        ; /* gobble each character */
    /* reset the error status of the stream */
    clearerr(stdin);
}

int getString(char* string, unsigned length, char* prompt)
{
	int finished = FALSE;
	char tempString[NAMELEN + EXTRACHARS];


	do
	{
		/* Provide input prompt */
		printf("%s", prompt);

		/* Accept input */
		fgets(tempString, length + EXTRACHARS, stdin);

		/* A string that doesn't have a newline character is too long */
		if (tempString[strlen(tempString) - 1] != '\n')
		{
			fprintf(stderr, "Input was too long\n");
			read_rest_of_line();
		}
		else if(tempString[1] == '\0')
        {
            return RTM;
        }
		else
		{
			finished = TRUE;
		}

	}while (finished == FALSE);

	/* Overwrite the \n character with \0 */
	tempString[strlen(tempString) -1] = '\0';

	/* Makes result available to calling function */
	strcpy(string, tempString);

	return TRUE;
}


