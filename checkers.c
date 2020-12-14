/*
 *    * checkers.c
 *        */
   
#include <stdio.h>
#include "checkers.h"
#include <limits.h>
#include <stdlib.h>

void initBoard(void)
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
  
void drawBoard(void)
{
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
   
int goFirst(void)
{
    char x;
    printf("Would you like to go first (y/n)\n");
    do
    {
        x = getchar();
    }
    while( ( x != 'y')&& ( x != 'Y') && (x != 'n') && (x != 'N') );
    {
        printf("Please enter the correct letter");
    }
    if((x == 'y') || (x=='Y'))
    {
        return 1;
    }
    else 
        return 0;
}

void playerMove(void)
{
    int x,y;
    while(1)
    {
        printf("which piece do you want to move? Enter row # press enter then Enter col #\n");
        scanf("%d",  &x);
        scanf("%d",  &y);
        row = x-1;
        col = y-1;
        if(spotEmpty(row,col) == 1)
        {
            printf("this spot is empty\n");
        }
        else if(board[row][col] != user)
        {
            printf("That is not your piece!\n");
        }
        if((spotEmpty(row,col) == 0) && (board[row][col] == user))
        {
            movePiece(row,col);
            break;
        }
    }

}

void movePiece(int row1, int col1)
{
    int x2,y2;
    while(1)
    {
        printf("where do you want to move it?\n");
        scanf("%d",  &x2);
        scanf("%d",  &y2);
        row2 = x2 - 1; 
        col2 = y2-1;
        printf("row1 = %d, col1 = %d\n",row1,col1);
        printf("row2 = %d, col2 = %d\n",row2,col2);
        printf("abs(row2-row1) = %d",abs(row2-row1));
        if( (abs(row2-row1) != 1) || (abs(col2-col1) != 1) )
        {
            printf("You cannot move more than one row or col at a time!\n");
            break;
        }
        if((row2 == row1) || (row2==row1++) || (col2==col1) )
        { 
            printf("You must move diagnolly!\n");
                break;
        }
        if (border(row2,col2)==0)
        {
            printf("That is not on the board!\n");
            break;
        }
        if (board[row2][col2] == 'x')
        {
            printf("That spot is occupied!");
            break;
        }
        else
        {
            removePiece(row,col);
            createPiece(row2,col2,user);
            break;
        }
        
    }
}

int border(int a, int b)
{
    if(a>=1 && a<= 8 && b>=1 && b<=8)
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
    board[a][b] = 'x';
    return;
}

int spotEmpty(int a, int b)
{
    if(board[a][b] == ' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}
  
void startGame(void)
{
    for(int x=0; x<INT_MAX; x++)
    {
        if(user == 'x')
        {
            playerMove();
            drawBoard();
        }
        if(computer == 'x')
        {
            computerMove();
            drawBoard();
        }
        if(checkPieces(user)== 0)
        {
            printf("YOU LOSE!");
        }
        if(checkPieces(computer)==0)
        {
            printf("YOU WIN!");
        }
    }
}

int checkPieces(char a)
{
    int pieces = 0;
    for(int y=0; y<boardSize; y++)
    {
        for(int z=0; z<boardSize; z++)
        {
            if(board[y][z]==a)
            {
                pieces++;
            }
        }
    } 
  return pieces;
}

void computerMove (void)
{
    int row, col;
    int x;
    while (1)
    {
        printf("Which piece(write rowcol as the same number) do you want to move?");
        scanf("%d", &x);
        row = x / 10 -1;
        col = x % 10 -1;
        if(spotEmpty(row,col) == 1)
        {
            printf("This spot is empty");
        }
        else if(board[row][col] == user)
        {
            printf("This is not your piece!");
        }
        if ((spotEmpty(row,col) == 0) && (board[row][col] != user))
        {
            movePieceCPU(row,col);
            break;
        }
    }
}

void movePieceCPU(int row1, int row2)
{
    int y;
    int col2;
    int row;
    int col;
    while (1)
    {
        printf("Where do you want to move it");
        scanf("%d", &y);
        row2 = y/ 10 - 1;
        col2 = y % 10 -1;
        col = y % 10-1;
        if (( row2 == row) || (row2 = row++))
        {
            printf("That move is illegal please try again!");
            break;
        }
        else if (( abs(row2-row) != 1) && ( abs(col2-col) != 1)) 
        {
            printf("That's illegal");
            break;
        }
        else if (border(row2,col2) == 0)
        {
            printf("That's illegal");
            break;
        }
        else if (board[row2][col2] == user)
        {
            if (abs(col2-col) == 1 )
            {
                if(spotEmpty(row2++,col2++)==1)
                {
                    removePiece(row2,col2);
                    createPiece(row2++,col2++,computer);
                    removePiece(row,col);
                    break;
                }
            }
            if (col2-col == -1)
            {
                if(spotEmpty(row2--,col2++) == 1)
                {
                    removePiece(row2,col2);
                    createPiece(row2--,col2++,computer);
                    removePiece(row,col);
                    break;
                }
            }
            else
            {
                removePiece(row,col);
                createPiece(row2,col2,computer);
                break;
            }
        }
    }
}
