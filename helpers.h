#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>


typedef enum boolean
{
    FALSE = 0,
    TRUE
} Boolean;


#define NEW_LINE_SPACE 1
#define NULL_SPACE 1

/**
 * This is used to compensate for the extra character spaces taken up by
 * the '\n' and '\0' when input is read through fgets().
 **/
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

#define EMPTY_STRING ""

/**
 * Call this function whenever you detect buffer overflow but only call this
 * function when this has happened.
 **/
void readRestOfLine();

/**
 * The function to get user input string
 */
Boolean getUserInputString(char* inputResult, int expectedLength);

/**
 * The function to get user input char
 */
char getUserInputChar(Boolean ignoreNewline);



#endif
