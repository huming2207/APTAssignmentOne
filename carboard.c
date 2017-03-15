#include <stdio.h>
#include "carboard.h"
#include "helpers.h"


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
    printf("Welcome to Car Board\n"
           "--------------------\n"
           "1. Play Game\n"
           "2. Show student information\n"
           "3. Quit\n\n");

    // As the requirement said, we need to handle any other unexpected input (except numeric stuff).
    // So I used char instead of other type to handle that.
    printf("Please enter your choice: ");
    char input = (char)fgetc(stdin);

    switch(input)
    {
        // Char "1" in ASCII is 49
        case 49:
        {
            helpMessageBeforeGame();
            break;
        }

        // Char "1" in ASCII is 49
        case 50:
        {
            showStudentInformation();
            mainMenu();
            break;
        }

        case 51:
        {
            break;
        }

        default:
        {
            printf("Invalid input.\n\n");
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
           "Press enter to continue...");

    int input = fgetc(stdin);

    if(input != 0)
    {
        displayEmptyBoard();
    }



}



