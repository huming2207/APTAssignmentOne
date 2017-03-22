#include "board.h"

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
        { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
        { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
        { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};


Cell BOARD_EMPTY[BOARD_HEIGHT][BOARD_WIDTH] =
{
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};


void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
    InputInfo inputInfo;
    displayBoard(board, NULL);

    printf("\n\nAt this stage of the program, only two commands are acceptable:\n"
                   "load <g>\n"
                   "quit\n\n");

    /* Set stage to Stage #2 */
    inputInfo = parseUserMenuInput(2);

    /* If input returns an error, try again. */
    if(inputInfo.commandInfo == CMD_ERROR)
    {
        printf("\n\nInvalid input\n\n");
        initialiseBoard(board);
    }

    switch(inputInfo.commandInfo)
    {
        case CMD_LOAD:
        {
            switch(inputInfo.boardToLoad)
            {
                case 1: loadBoard(NULL, BOARD_1); break;
                case 2: loadBoard(NULL, BOARD_2); break;
                default: break; /* That's impossible, as it was blocked when parsing user input */
            }
        }

        case CMD_QUIT: mainMenu(); break;

        default: break;
    }



}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
    InputInfo inputInfo;
    displayBoard(boardToLoad, NULL);
    printf("\n\nAt this stage of the program, only three commands are acceptable:\n"
                   "load <g>\n"
                   "init <x>,<y>,<direction>\n"
                   "quit\n\n");

    /* Set stage to Stage #3 */
    inputInfo = parseUserMenuInput(3);

    if(inputInfo.commandInfo == CMD_ERROR)
    {
        printf("\n\nInvalid input\n\n");
        loadBoard(board, boardToLoad);
        return;
    }

    switch(inputInfo.commandInfo)
    {
        case CMD_LOAD:
        {
            switch(inputInfo.boardToLoad)
            {

            }

        }

        case CMD_QUIT: mainMenu(); break;
        default: break;
    }

    return;
}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
    /* TODO */
    return FALSE;
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
                             Player * player)
{
    /* TODO */
    return PLAYER_MOVED;
}

void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
    int boardHeight, boardFirstRow, boardWidth;

    /* Print the first element (on the top-left corner) */
    printf("\n| |");

    /* Print the first row , i.e. "| |0|1|2|3|4|5|6|7|8|9|" */
    for(boardFirstRow = 0; boardFirstRow <= 9; boardFirstRow++)
    {
        printf("%d|", boardFirstRow);
    }

    /* print for each row and each element appended, i.e. "|0 to 9| | | | | | | | | | |" */
    for(boardHeight = 0; boardHeight <= (BOARD_HEIGHT - 1); boardHeight++)
    {
        printf("\n|%d|", boardHeight);
        for(boardWidth = 0; boardWidth <= (BOARD_WIDTH - 1); boardWidth++)
        {
            /*
             * If matches player's position, then print the player arrow;
             * If it's not then print the block.
             */
            switch(board[boardHeight][boardWidth])
            {
                case EMPTY: printf("%s|", EMPTY_OUTPUT); break;
                case BLOCKED: printf("%s|", BLOCKED_OUTPUT); break;
                case PLAYER:
                {
                    /* print player by pre-defined direction */
                    switch(player->direction)
                    {
                        case EAST: printf("%s|", DIRECTION_ARROW_OUTPUT_EAST); break;
                        case SOUTH: printf("%s|", DIRECTION_ARROW_OUTPUT_SOUTH); break;
                        case WEST: printf("%s|", DIRECTION_ARROW_OUTPUT_WEST); break;
                        case NORTH: printf("%s|", DIRECTION_ARROW_OUTPUT_NORTH); break;
                    }
                    break;
                }
            }

        }
    }
}


InputInfo parseUserMenuInput(int stage)
{
    InputInfo inputInfo;
    char input[17];
    char* splittedInput;

    /* Get user input */
    getUserInputString(input, 15);

    /* User input must be longer than 4, otherwise it's invalid. */
    if((int)strlen(input) < 4)
    {
        inputInfo.commandInfo = CMD_ERROR;
        printf("\n\nInvalid input\n\n");
        return inputInfo;
    }

    /* Do a string split, get the first string */
    splittedInput = strtok(input, " ");

    /* Do the first judgement to see if it's "load" or "quit" */
    if(strcmp(&splittedInput[0], "load") == 0)
    {
        /* Wait and have a look at the next char, should be 1 or 2, after processing, jump out from the while loop */
        while (splittedInput != NULL)
        {
            splittedInput = strtok (NULL, " ");
            if(strcmp(&splittedInput[0], "1") == 0)
            {
                splittedInput = NULL;
                inputInfo.commandInfo = CMD_LOAD;
                inputInfo.boardToLoad = 1;
                return inputInfo;
            }
            else if(strcmp(&splittedInput[0], "2") == 0)
            {
                splittedInput = NULL;
                inputInfo.commandInfo = CMD_LOAD;
                inputInfo.boardToLoad = 2;
                return inputInfo;
            }
            else
            {
                splittedInput = NULL;
                inputInfo.commandInfo = CMD_ERROR;
                printf("\n\nInvalid input\n\n");
                return inputInfo;
            }
        }
    }
    else if(strcmp(&splittedInput[0], "quit") == 0)
    {
        printf("\n");
        inputInfo.commandInfo = CMD_QUIT;
        return inputInfo;
    }
    else if(strcmp(&splittedInput[0], "init") == 0 && stage == 3)
    {
        inputInfo.commandInfo = CMD_INIT;
        return inputInfo;
    }
    else
    {
        inputInfo.commandInfo = CMD_ERROR;
        printf("\n\nInvalid input\n\n");
        return inputInfo;
    }
}


