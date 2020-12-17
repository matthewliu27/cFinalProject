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
    player1King = 'X';
    player2King = 'O';

    char x;
    printf("Do you want to play checkers? (y/n)\n");
        x = getchar();
    while (10 > 1)
    {
        if ((x != 'y') && (x != 'Y') && (x != 'n') && (x != 'N'))
        {
            printf("Enter a valid choice!\n");
            x = getchar();
        }
        if ((x == 'y') || (x == 'Y'))
        {
            printf("Have fun\n");
            startGame();
        }
        if ((x == 'n') || (x == 'N'))
        {
            printf("OK, bye!\n");
            break;
        }
    }
    

}
