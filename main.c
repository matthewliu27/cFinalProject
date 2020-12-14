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
    user = 'x';
    computer = 'o';
    int choice = goFirst();
    if(choice == 0) 
    {
        user = 'o';
        computer = 'x';
    }


    initBoard();
    drawBoard();
    startGame();
}



