#include "game.h"

void playGame()
{
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

    /* TODO */
    /**
     * This is some sample code using the functions provided.
     *
     * Note that NULL is passed as the "Player * player" parameter as there is
     * no player cell present on the board in this example.
     */
    initialiseBoard(board);
    displayBoard(board, NULL);

    loadBoard(board, BOARD_1);
    displayBoard(board, NULL);

    loadBoard(board, BOARD_2);
    displayBoard(board, NULL);
}
