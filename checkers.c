/*
 * checkers.c
 */

#include <stdio.h>
#include "checkers.h"

void initBoard(void)
{
    int row;
    int col;

    for (row = 0; row < boardSize; row++)
    {
        for (col = 0; col < boardSize; col++)
        {
            board[row][col] = ' ';
        }
    }
    return;
}
