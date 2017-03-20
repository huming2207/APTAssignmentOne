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
 * Now this method contains some code from course sample docs.
 * My original ones always have stall issues.
 *
 */
Boolean getUserInputString(char* inputResult, int32_t expectedLength)
{
    return FALSE;
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
