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

Boolean getUserInputString(char* inputResult, int32_t expectedLength)
{
    // If the string length is longer than expected, it must be something wrong.
    // Clear it up and return a FALSE.
    if((int32_t)strlen(inputResult) > expectedLength)
    {
        readRestOfLine();
        return FALSE;
    }
    else
    {
        fgets(inputResult, expectedLength + 2, stdin);
        return TRUE;
    }
};
