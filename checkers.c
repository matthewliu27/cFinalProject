/*
 *    * checkers.c
 *        */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "checkers.h"
#include <limits.h>
#include <stdlib.h>

void initBoard(void)
{
    for (int cold = 0; cold < boardSize; cold++)
    {
        if (cold % 2 == 0)
        {
            board[5][cold] = 'x';
            board[7][cold] = 'x';
            board[1][cold] = 'o';
        }
        if (cold % 2 == 1)
        {
            board[0][cold] = 'o';
            board[6][cold] = 'x';
            board[2][cold] = 'o';
        }

    }
    return;
}

void drawBoard(void)
{
    printf("\n");
    printf("\t 1   2   3   4   5   6   7   8\n\n");
    for (int rowd = 0; rowd < boardSize; rowd++)
    {
        printf("\t   *   *   *   *   *   *   *   \n");
        printf("%d\t %c * %c * %c * %c * %c * %c * %c * %c \n", rowd + 1, board[rowd][0], board[rowd][1], board[rowd][2], board[rowd][3], board[rowd][4], board[rowd][5],
            board[rowd][6], board[rowd][7]);
        printf("\t   *   *   *   *   *   *   *   \n");
        printf("\t********************************\n");
    }
}


void player1Move(void)
{
    int x, y;
    while (1)
    {
        printf("It is player1's turn (x)\n");
        printf("which piece do you want to move? Enter row # press enter then Enter col #\n");
        scanf("%d", &x);
        scanf("%d", &y);
        row1 = x - 1;
        col1 = y - 1;
        if (((spotEmpty(row1, col1) == 0) && (board[row1][col1] == player1)))
        {
            kingStatus = 0;
            player1movePiece(row1, col1);
            break;
        }
        else if ((spotEmpty(row1, col1) == 0) && (board[row1][col1] == player1King))
        {
            kingStatus = 1;
            player1movePiece(row1, col1);
            break;
        }
        else if (spotEmpty(row1, col1) == 1)
        {
            printf("this spot is empty\n");
        }
        else if ((board[row1][col1] != player1) || (board[row1][col1] != player1King))
        {
            printf("That is not your piece!\n");
        }
    }
}

void player1movePiece(int rowdf, int coldf)
{
    int x2, y2;
    while (1)
    {
        printf("where do you want to move it?\n");
        printf("kingStatus = %d\n", kingStatus);
        scanf("%d", &x2);
        scanf("%d", &y2);
        row2 = x2 - 1;
        col2 = y2 - 1;
        if (kingStatus == 0)
        {
            printf("row2 = %d\n", row2);
            if ((abs(row2 - rowdf) != 1) || (abs(col2 - coldf) != 1))
            {
                printf("You cannot move more than one row or col at a time!\n");
                printf("abs(row2-rowdf) = %d abs(col2-coldf) = %d!\n", row2 - rowdf, col2 - coldf);
            }
            else if (((row2 == rowdf) && (col2 != coldf)) || ((col2 == coldf) && (row2 != coldf)))
            {
                printf("You must move diagnolly!\n");
            }
            if (row2 > rowdf)
            {
                printf("Regular pieces can't move backwards!\n");
            }
            else if (border(row2, col2) == 1)
            {
                printf("That is not on the board!\n");
            }
            else if (board[row2][col2] == 'x')
            {
                printf("That spot is occupied!");
            }
            else if (board[row2][col2] == 'o')
            {
                if (col2 - col1 == 1)
                {
                    row2--; /*spotEmpty somehow alters the value of row2 and col2?? */
                    col2++; /*This is to check the value of up 1 right 1 temporarily */
                    if (spotEmpty(row2, col2) == 1)
                    {
                        row2++; /* revert row2 and col2 back to correct values */
                        col2--;
                        removePiece(row2, col2);
                        removePiece(rowdf, coldf);
                        row2--; /*set row2 and col2 to up 1 right 1 to make jump  */
                        col2++;
                        createPiece(row2, col2, player1);
                        printf("you removed a piece!\n");
                        break;
                    }
                    else
                    {
                        printf("There's no space to make a jump!\n");
                        continue;
                    }
                }
                else if (col2 - col1 == -1)
                {
                    row2--; /*spotEmpty somehow alters the value of row2 and col2?? */
                    col2--; /* This is to check the value of up 1 left 1 temporarlily */
                    if (spotEmpty(row2, col2) == 1)
                    {
                        row2++; /* revert back to origin value of row2 and col2 */
                        col2++;
                        removePiece(row2, col2);
                        removePiece(row1, col1);
                        row2--; /* set row2 and col2 to up 1 left 1 to make jump */
                        col2--;
                        createPiece(row2, col2, player1);
                        printf("you removed a piece!\n");
                        break;
                    }
                    else
                    {
                        printf("There's no space to make a jump!\n");
                        continue;
                    }
                }
            }
            else
            {
                removePiece(rowdf, coldf);
                removePiece(row1, col1);
                createPiece(row2, col2, player1);
                break;
            }
        }

    }
}

int border(int a, int b)
{
    if ((a < 0) || (a > 7) || (b < 0) || (b > 7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void removePiece(int a, int b)
{
    board[a][b] = ' ';
    return;
}

void createPiece(int a, int b, char c)
{
    board[a][b] = c;
    return;
}


int spotEmpty(int a, int b)
{
    if (board[a][b] == ' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void startGame(void)
{
    for (int x = 0; x < INT_MAX; x++)
    {
        player1Move();
        drawBoard();
        player2Move();
        drawBoard();
    }
    if (checkPieces(player1) == 0)
    {
        printf("PlAYER 2 WINS!");
    }
    if (checkPieces(player2) == 0)
    {
        printf("PLAYER 1 WINS!");
    }
}


int checkPieces(char a)
{
    int pieces = 0;
    for (int y = 0; y < boardSize; y++)
    {
        for (int z = 0; z < boardSize; z++)
        {
            if (board[y][z] == a)
            {
                pieces++;
            }
        }
    }
    return pieces;
}

void player2Move(void)
{
    int x, y;
    while (1)
    {
        printf("It is player2's turn (o)\n");
        printf("which piece do you want to move? Enter row # press enter then Enter col #\n");
        scanf("%d", &x);
        scanf("%d", &y);
        row3 = x - 1;
        col3 = y - 1;
        if (((spotEmpty(row3, col3) == 0) && (board[row3][col3] == player2)) || ((spotEmpty(row3, col3) == 0) && (board[row3][col3] == player2King)))
        {
            player2movePiece(row3, col3);
            break;
        }
        else if (spotEmpty(row3, col3) == 1)
        {
            printf("this spot is empty\n");
        }
        else if ((board[row3][col3] != player2) || (board[row3][col3] != player2King))
        {
            printf("That is not your piece!\n");
        }
    }

}

void player2movePiece(int rowdf, int coldf)
{
    int x2, y2;
    while (1)
    {
        printf("where do you want to move it?\n");
        scanf("%d", &x2);
        scanf("%d", &y2);
        row4 = x2 - 1;
        col4 = y2 - 1;
        if ((abs(row4 - row3) != 1) || (abs(col4 - col3) != 1))
        {
            printf("You cannot move more than one row or col at a time!\n");
            continue;
        }
        if ((row4 == row3) || (row4 == row3--) || (col4 == col3))
        {
            printf("You must move diagnolly!\n");
            continue;
        }
        if (border(row4, col4) == 1)
        {
            printf("That is not on the board!\n");
            continue;
        }
        if (board[row4][col4] == 'o')
        {
            printf("That spot is occupied!");
            continue;
        }
        if (board[row4][col4] == 'x')
        {
            if (col4 - col3 == 1) /*jumping from left ro right */
            {
                row4++; /*checking down 1 right 1r*/
                col4++;
                if (spotEmpty(row4, col4) == 1)
                {
                    row4--; /*back to original */
                    col4--;
                    removePiece(row4, col4);
                    removePiece(rowdf, coldf);
                    row4++; /* down 1 right 1 */
                    col4++;
                    createPiece(row4, col4, player2);
                    printf("you removed a piece!\n");
                    break;
                }
                else
                {
                    printf("There's no space to jump!\n");
                    continue;
                }

            }
            if (col4 - col3 == -1)
            {
                row4++; /*checking down 1 left 1 */
                col4--;
                if ((spotEmpty(row4, col4)) == 1)
                {
                    row4--; /* revert back to original */
                    col4++;
                    removePiece(row4, col4);
                    removePiece(rowdf, coldf);
                    row4++; /* down 1 left 1 of x piece that is being eaten */
                    col4--;
                    createPiece(row4, col4, player2);
                    printf("you removed a piece!\n");
                    break;
                }
                else
                {
                    printf("There's no space to jump!\n");
                    continue;
                }
            }
        }
        else
        {
            removePiece(rowdf, coldf);
            createPiece(row4, col4, player2);
            break;
        }
    }
}
