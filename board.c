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
                case 1: loadBoard(NULL, BOARD_1); break;
                case 2: loadBoard(NULL, BOARD_2); break;
                default: break; /* That's impossible, as it was blocked when parsing user input */
            }
            break;
        }
        case CMD_INIT:
        {
            startGame(boardToLoad, inputInfo);
        }
        case CMD_QUIT: mainMenu(); break;
        default: break;
    }

    return;
}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
    int heightIndex, widthIndex;

    if(position.x < BOARD_WIDTH && position.y < BOARD_HEIGHT)
    {
        /* Remove all players before assign the player position */
        for(heightIndex = 0; heightIndex < BOARD_HEIGHT; heightIndex++)
        {
            for(widthIndex = 0; widthIndex < BOARD_WIDTH; widthIndex++)
            {
                if(board[heightIndex][widthIndex] == PLAYER)
                {
                    board[heightIndex][widthIndex] = EMPTY;
                }
            }
        }

        board[position.y][position.x] = PLAYER;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
    Position position;
    position = getNextForwardPosition(player);

    /* Step 1, detect if the cell has been occupied or out of bound */
    if(position.x >= BOARD_HEIGHT || position.y >= BOARD_WIDTH ||
            position.x < 0 || position.y < 0)
    {
        return OUTSIDE_BOUNDS;
    }
    else if(board[position.y][position.x] != EMPTY)
    {
        return CELL_BLOCKED;
    }
    else
    {
        updatePosition(player, position);
        if(placePlayer(board, player->position) == TRUE)
        {
            return PLAYER_MOVED;
        }
        else
        {
            return OUTSIDE_BOUNDS;
        }
    }
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

    /* print row header, i.e. "|0 to 9|" */
    for(boardHeight = 0; boardHeight <= (BOARD_HEIGHT - 1); boardHeight++)
    {
        printf("\n|%d|", boardHeight);

        /* print for each row and each element appended, i.e. "| | | | | | | | | | |" */
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
                    /* In some occasions the Player can be NULL, so I need to add something to handle this. */
                    if(player != NULL)
                    {
                        /* print player by pre-defined direction */
                        switch(player->direction)
                        {
                            case EAST: printf("%s|", DIRECTION_ARROW_OUTPUT_EAST); break;
                            case SOUTH: printf("%s|", DIRECTION_ARROW_OUTPUT_SOUTH); break;
                            case WEST: printf("%s|", DIRECTION_ARROW_OUTPUT_WEST); break;
                            case NORTH: printf("%s|", DIRECTION_ARROW_OUTPUT_NORTH); break;
                        }
                    }
                    else
                    {
                        /* Fill another empty space into the cell */
                        printf("%s|", EMPTY_OUTPUT); break;
                    }
                    break;
                }
            }

        }
    }
}

void startGame(Cell board[BOARD_HEIGHT][BOARD_WIDTH], InputInfo inputInfo)
{
    Player player;

    player = playerInit(inputInfo, board);
    if(placePlayer(board, player.position) == TRUE)
    {
        gameHandler(board, &player);
    }
    else
    {
        printf("\n\nInvalid input\n\n");
        loadBoard(NULL, board);
        return;
    }
}

void gameHandler(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player* player)
{
    InputInfo inputInfo;
    PlayerMove nextPlayerMove;

    displayBoard(board, player);
    printf("\n\nAt this stage of the program, only four commands are acceptable:\n"
                   "forward (or f)\n"
                   "turn_left (or l)\n"
                   "turn_right (or r)\n"
                   "quit\n\n");

    inputInfo = parseUserMenuInput(4);

    switch(inputInfo.commandInfo)
    {
        case CMD_TURN_RIGHT:
        {
            turnDirection(player, TURN_RIGHT);
            gameHandler(board, player);
            break;
        }
        case CMD_TURN_LEFT:
        {
            turnDirection(player, TURN_LEFT);
            gameHandler(board, player);
            break;
        }
        case CMD_FORWARD:
        {
            nextPlayerMove = movePlayerForward(board, player);

            switch(nextPlayerMove)
            {
                case PLAYER_MOVED:
                {
                    printf("\n\nPlayer moved.\n\n");
                    player->moves = player->moves + 1;
                    gameHandler(board, player);
                    break;
                }
                case CELL_BLOCKED:
                {
                    printf("\n\nUnable to move - cell is blocked.\n\n");
                    gameHandler(board, player);
                    break;
                }
                case OUTSIDE_BOUNDS:
                {
                    printf("\n\nUnable to move - outside bounds.\n\n");
                    gameHandler(board, player);
                    break;
                }
            }
            break;
        }
        case CMD_QUIT:
        {
            printf("\n\nTotal player moves: %d\n\n", player->moves);
            mainMenu();
            break;
        }
        default:
        {
            gameHandler(board, player);
            break;
        }
    }

    return;
}


Player playerInit(InputInfo inputInfo, Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
    Player player;

    player.position = inputInfo.position;
    player.direction = inputInfo.direction;

    return player;
}

InputInfo parseLoadCommand(char* splitInput)
{
    /**
     * Parse "load" command, if 1 then load the first board, if 2 then load second board.
     */

    InputInfo inputInfo;

    /* Wait and have a look at the next char, should be 1 or 2, after processing, jump out from the while loop */
    while (splitInput != NULL)
    {
        splitInput = strtok (NULL, " ");
        if(strcmp(&splitInput[0], "1") == 0)
        {
            splitInput = NULL;
            inputInfo.commandInfo = CMD_LOAD;
            inputInfo.boardToLoad = 1;
            return inputInfo;
        }
        else if(strcmp(&splitInput[0], "2") == 0)
        {
            splitInput = NULL;
            inputInfo.commandInfo = CMD_LOAD;
            inputInfo.boardToLoad = 2;
            return inputInfo;
        }
        else
        {
            splitInput = NULL;
            inputInfo.commandInfo = CMD_ERROR;
            printf("\n\nInvalid input\n\n");
            return inputInfo;
        }
    }

    /* Yet another useless stuff to keep the compiler be quiet. */
    inputInfo.commandInfo = CMD_ERROR;
    return inputInfo;
}

InputInfo parseInitCommand(char* splitInput)
{
    /**
    * "init" contains a group of arguments
    *
    *  The format is: PosX,PosY,Direction
    *  For example: 1,2,south
    *
    *  As it shown above, the first two are digits, so I need to parse into int type;
    *  then later on, the direction phrase will be cut and parse separately.
    */

    InputInfo inputInfo;
    char initString[15];
    char initArgument[15];
    int strSourceIndex;
    int strDestIndex;
    char directionString[6];

    while (splitInput != NULL)
    {
        splitInput = strtok (NULL, " ");
        strcpy(initString, &splitInput[0]);

        if(initString[1] == ',' || initString[3] == ',')
        {
            splitInput = NULL;
            inputInfo.commandInfo = CMD_INIT;
            inputInfo.position.x = initString[0] - '0'; /* minus '0' to get the real digit (based on ASCII, '0' is 48)*/
            inputInfo.position.y = initString[2] - '0'; /* minus '0' to get the real digit (based on ASCII, '0' is 48)*/
            strcpy(initArgument, initString);

            /* Parse direction to inputInfo, cut and move the argument phrase first, then parse. */
            for(strSourceIndex = 4; strSourceIndex <= 9; strSourceIndex++)
            {
                strDestIndex = strSourceIndex - 4;
                directionString[strDestIndex] = initArgument[strSourceIndex];
            }

            if(strcmp(directionString, DIRECTION_EAST) == 0)
            {
                inputInfo.direction = EAST;
            }
            else if(strcmp(directionString, DIRECTION_SOUTH) == 0)
            {
                inputInfo.direction = SOUTH;
            }
            else if(strcmp(directionString, DIRECTION_WEST) == 0)
            {
                inputInfo.direction = WEST;
            }
            else if(strcmp(directionString, DIRECTION_NORTH) == 0)
            {
                inputInfo.direction = NORTH;
            }
            else
            {
                inputInfo.commandInfo = CMD_ERROR;
                printf("\n\nInvalid input\n\n");
                return inputInfo;
            }

            return inputInfo;
        }
        else
        {
            splitInput = NULL;
            inputInfo.commandInfo = CMD_ERROR;
            printf("\n\nInvalid input\n\n");
            return inputInfo;
        }
    }

    /* Useless, just for shut up the compiler warnings. */
    inputInfo.commandInfo = CMD_ERROR;
    printf("\n\nInvalid input\n\n");
    return inputInfo;
}


InputInfo parseUserMenuInput(int stage)
{
    InputInfo inputInfo;
    char input[17];
    char* splitInput;

    /* Get user input */
    getUserInputString(input, 15);

    /* User input must be longer than 1, otherwise it's invalid. */
    if((int)strlen(input) < 1)
    {
        inputInfo.commandInfo = CMD_ERROR;
        printf("\n\nInvalid input\n\n");
        return inputInfo;
    }

    /* Do a string split, get the first string */
    splitInput = strtok(input, " ");

    /**
     * User command parsing section
     * "load"               -> parseLoadCommand(splitInput)
     * "quit"               -> Return a CMD_QUIT information
     * "init"               -> parseInitCommand(splitInput)
     * "forward" and "f"    -> Return a CMD_FORWARD information
     * "turn_left" and "l"  -> Return a CMD_TURN_LEFT information
     * "turn_right" and "r" -> Return a CMD_TURN_RIGHT information
     * other invalid stuff  -> Return a CMD_ERROR information
     */
    if(strcmp(&splitInput[0], "load") == 0 && stage != 4)
    {
        return parseLoadCommand(splitInput);
    }
    else if(strcmp(&splitInput[0], "quit") == 0)
    {
        inputInfo.commandInfo = CMD_QUIT;
        return inputInfo;
    }
    else if(strcmp(&splitInput[0], "init") == 0 && stage == 3)
    {
        return parseInitCommand(splitInput);
    }
    else if((strcmp(&splitInput[0], "forward") == 0 || strcmp(&splitInput[0], "f") == 0) && stage == 4)
    {
        inputInfo.commandInfo = CMD_FORWARD;
        return inputInfo;
    }
    else if((strcmp(&splitInput[0], "turn_left") == 0 || strcmp(&splitInput[0], "l") == 0) && stage == 4)
    {
        inputInfo.commandInfo = CMD_TURN_LEFT;
        return inputInfo;
    }
    else if((strcmp(&splitInput[0], "turn_right") == 0 || strcmp(&splitInput[0], "r") == 0) && stage == 4)
    {
        inputInfo.commandInfo = CMD_TURN_RIGHT;
        return inputInfo;
    }
    else
    {
        inputInfo.commandInfo = CMD_ERROR;
        printf("\n\nInvalid input\n\n");
        return inputInfo;
    }
}
