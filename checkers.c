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

void drawBoard(void)
{
    int row;
    row=0;
    printf("\n");
    while (row < 8)
    {
        printf("   *   *   *   *   *   *   *   *\n");
        printf(" %c * %c * %c * %c * %c * %c * %c * %c *\n", board[row][0], board[row][1], board[row][2], board[row][3], board[row][4], board[row][5],
                                  board[row][6], board[row][7]);
        printf("   *   *   *   *   *   *   *   *\n");
        row++;
        return;
    }
}

