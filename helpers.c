#include <stdio.h>
#include "helpers.h"

void readRestOfLine()
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != '\n')
    { } /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}

/**
 *
 * Now this method contains some code from course sample docs (getString-basic.c).
 * My original ones always have some stall issues, so use this one instead.
 * I changed some parts of it to make it more robust and satisfy my needs.
 *
 */
Boolean getUserInputString(char* inputResult, int32_t expectedLength)
{
    /* According to clang compiler, variable length arrays are a C99 feature. So I use a fixed one here */
    char input[50];
    Boolean finished;
    finished = FALSE;

    while(finished == FALSE)
    {
        /* Report FALSE if the string is too long */
        if((expectedLength + 2) <= 50)
        {
            fgets(input, expectedLength + 2, stdin);
        }
        else
        {
            return FALSE;
        }

        /* Force append \0 to end this string */
        input[strlen(input) - 1] = '\0';

        /* Copy the string to the result pointer */
        strcpy(inputResult, input);

        finished = TRUE;
    }

    return TRUE;
}


/**
 *  Get a single char input from user
 *
 */
char getUserInputChar(Boolean ignoreNewline)
{
    char input[3];
    fgets(input, 2, stdin);

    /* Ignoring new line inspection or not... */
    if(ignoreNewline != FALSE)
    {
        if(input[0] == '\n' || input[0] == '\r')
        {
            printf("\n\nInvalid input.\n\n");
            return '\0';
        }
        else
        {
            readRestOfLine();
            return input[0];
        }
    }
    else
    {
        return input[0];
    }
}


