#include <stdio.h>
#include "carboard.h"


int main()
{
    mainMenu();
    return EXIT_SUCCESS;
}

void showStudentInformation()
{
    printf("\n-----------------------------------\n");
    printf("Name: %s\n", STUDENT_NAME);
    printf("Student ID: %s\n", STUDENT_ID);
    printf("Email: %s\n", STUDENT_EMAIL);
    printf("-----------------------------------\n\n");
}

void mainMenu()
{
    char input;
    printf("Welcome to Car Board\n"
           "--------------------\n"
           "1. Play Game\n"
           "2. Show student information\n"
           "3. Quit\n\n");

    /**
     * As the requirement said, we need to handle any other unexpected input (except numeric stuff).
     * So I used char instead of other type to handle that.
     */
    printf("Please enter your choice: ");

    input = getUserInputChar(TRUE);

    /* When input returns "\0", then it must be something wrong. Do the whole method again. */
    if(input == '\0')
    {
        mainMenu();
    }

    switch(input)
    {
        /* Char "1" in ASCII is 49 */
        case 49:
        {
            helpMessageBeforeGame();
            break;
        }

        /* Char "2" in ASCII is 50 */
        case 50:
        {
            showStudentInformation();
            mainMenu();
            break;
        }

        /* Char "3" in ASCII is 51 */
        case 51:
        {
            exit(0);
        }

        default:
        {
            printf("\n\nInvalid input.\n\n");
            mainMenu();
            break;
        }
    }
}

    void helpMessageBeforeGame()
    {
        printf("\n"
               "You can use the following commands to play the game:\n"
               "load <g>\n"
               "   g: number of the game board to load\n"
               "init <x>,<y>,<direction>\n"
               "   x: horizontal position of the car on the board (between 0 & 9)\n"
               "   y: vertical position of the car on the board (between 0 & 9)\n"
               "   direction: direction of the car's movement (north, east, south, west)\n"
               "forward (or f)\n"
               "turn_left (or l)\n"
               "turn_right (or r)\n"
               "quit\n"
               "\n"
               "Press enter to continue...   ");

        /**
         * As it required in the message of sample carboard binary provided on the blackboard, only **press enter** is expected.
         * But if you press other keys in the carboard binary, it will also jump into the next step.
         * That's probably a bug? (or...just became a feature lol?!)
         * Anyway, here I have limited the input to enter key ONLY.
         * */
    if(getUserInputChar(FALSE) == '\n')
    {
        playGame();
    }
    else
    {
        printf("\n\nInvalid input.\n\n");
        readRestOfLine();
        helpMessageBeforeGame();
    }

}



