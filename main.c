/*
 * main.c
 */

#include <stdio.h>
#include "checkers.h"

void initBoard(void);
void drawBoard(void);

char board[boardSize][boardSize];

int main() 
{
    player1 = 'x';
    player2 = 'o';

    initBoard();
    drawBoard();
    startGame();
}



