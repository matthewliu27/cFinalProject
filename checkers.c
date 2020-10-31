/*
 * checkers.c
 */

#include <stdio.h>
#include "checkers.h"

void initBoard(void)
{ 
int col;

{
for(col =0; col<boardSize; col++)
   {
    if(col % 2 == 0)
    {
        board[5][col]= 'x';
        board[7][col] = 'x';
        board[1][col]= 'o';
     }

    if(col % 2 == 1) 
    {
        board[0][col] = 'o';
        board[6][col] = 'x';
        board[2][col] = 'o';
    }
   }
   return;
 
 }
}
void drawBoard(void)
{
    int row;
    printf("\n");
   for ( row = 0; row < boardSize ; row++)  
    {
        printf("   *   *   *   *   *   *   *   \n");
        printf(" %c * %c * %c * %c * %c * %c * %c * %c \n", board[row][0], board[row][1], board[row][2], board[row][3], board[row][4], board[row][5],
                                  board[row][6], board[row][7]);
        printf("   *   *   *   *   *   *   *   \n");
        printf("********************************\n");
    }
}

