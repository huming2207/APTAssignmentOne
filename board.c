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
    displayBoard(board, NULL);
    printf("\n\nAt this stage of the program, only two commands are acceptable:\n"
                   "load <g>\n"
                   "quit\n\n");
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
    /* TODO */
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

void displayEmptyBoard()
{
    int boardHeightIndex, boardFirstRow, boardWidthIndex;
    /* Print the first element (on the top-left corner) */
    printf("\n| |");

    /* Print the first row , i.e. "| |0|1|2|3|4|5|6|7|8|9|" */
    for(boardFirstRow = 0; boardFirstRow <= 9; boardFirstRow++)
    {
        printf("%d|", boardFirstRow);
    }

    /* print for each row and each element appended, i.e. "|0 to 9| | | | | | | | | | |" */
    for(boardHeightIndex = 0; boardHeightIndex <= (BOARD_HEIGHT - 1); boardHeightIndex++)
    {
        printf("\n|%d|", boardHeightIndex);
        for(boardWidthIndex = 0; boardWidthIndex <= (BOARD_WIDTH - 1); boardWidthIndex++)
        {
            printf("%s|", EMPTY_OUTPUT);
        }
    }


}
