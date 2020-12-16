/*
 *    * checkers.c
 *        */
   
#include <stdio.h>
#include "checkers.h"
#include <limits.h>
#include <stdlib.h>

void initBoard(void)
{
    for(int cold =0; cold<boardSize; cold++)
    {
        if(cold % 2 == 0)
        {
            board[5][cold]= 'x';
            board[7][cold] = 'x';
            board[1][cold]= 'o';
        }
        if(cold % 2 == 1)
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
    for (int rowd = 0; rowd < boardSize ; rowd++)
    {
        printf("\t   *   *   *   *   *   *   *   \n");
        printf("%d\t %c * %c * %c * %c * %c * %c * %c * %c \n",rowd+1, board[rowd][0], board[rowd][1], board[rowd][2], board[rowd][3], board[rowd][4], board[rowd][5],
                board[rowd][6], board[rowd][7]);
        printf("\t   *   *   *   *   *   *   *   \n");
        printf("\t********************************\n");
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
        printf("row2 = %d, col2 = %d before jump\n",row2,col2);
        
        if( (abs(row2-row1) != 1) || (abs(col2-col1) != 1) )
        {
            printf("You cannot move more than one row or col at a time!\n");
            break;
        }
        else if((row2 == row1) || (row2==row1++) || (col2==col1) )
        { 
            printf("You must move diagnolly!\n");
                break;
        }
        else if (border(row2,col2)==0)
        {
            printf("That is not on the board!\n");
            break;
        }
        else if (board[row2][col2] == 'x')
        {
            printf("That spot is occupied!");
            break;
        }
        else if(board[row2][col2] == 'o')
        {
            if(col2-col1 == 1 )
            {
                row2--; /*spotEmpty somehow alters the value of row2 and col2?? */
                col2++; /*This is to check the value of up 1 right 1 temporarily */
                if(spotEmpty(row2,col2) == 1)
                {
                    row2++; /* revert row2 and col2 back to correct values */
                    col2--;
                    removePiece(row2,col2);
                    removePiece(row,col);
                    row2--; /*set row2 and col2 to up 1 right 1 to make jump  */
                    col2++;
                    createPiece(row2,col2,user);
                    printf("you removed a piece!\n");
                    break;
                }
                else
                {
                    printf("There's no space to make a jump!\n");
                    break;
                }
            }
        
            else if(col2-col1 == -1)
            {
                row2--; /*spotEmpty somehow alters the value of row2 and col2?? */
                col2--; /* This is to check the value of up 1 left 1 temporarlily */
                if(spotEmpty(row2,col2) == 1)
                {
                    row2++; /* revert back to origin value of row2 and col2 */
                    col2++;
                    removePiece(row2,col2);
                    removePiece(row,col);
                    row2--; /* set row2 and col2 to up 1 left 1 to make jump */ 
                    col2--;
                    createPiece(row2,col2,user);
                    printf("you removed a piece!\n");
                    break;
                }
                else
                {
                    printf("There's no no space to make a jump!\n");
                    break;
                }
            }
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
    board[a][b] = c;
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
}
  
void startGame(void)
{
    for(int x=0; x<INT_MAX; x++)
    {
        if(user == 'x')
        {
            playerMove();
            drawBoard();
            computerMove();
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
    int x,y;
    while(1)
    {
        printf("which piece do you want to move? Enter row # press enter then Enter col #\n");
        scanf("%d",  &x);
        scanf("%d",  &y);
        row3 = x-1;
        col3 = y-1;
        if(spotEmpty(row3,col3) == 1)
        {
            printf("this spot is empty\n");
        }
        else if(board[row3][col3] == user)
        {
            printf("That is not your piece!\n");
        }
        if((spotEmpty(row3,col3) == 0) && (board[row3][col3] == computer))
        {
            movePieceCPU(row3,col3);
            break;
        }
    }

}

void movePieceCPU(int rowdf, int coldf)
{
    int x2,y2;
    while(1)
    {
        printf("where do you want to move it?\n");
        scanf("%d",  &x2);
        scanf("%d",  &y2);
        row4 = x2 - 1; 
        col4 = y2-1;
        if( (abs(row4-row3) != 1) || (abs(col4-col3) != 1) )
        {
            printf("You cannot move more than one row or col at a time!\n");
            break;
        }
        if((row4 == row3) || (row4==row3--) || (col4==col3) )
        { 
            printf("You must move diagnolly!\n");
                break;
        }
        if (border(row4,col4)==0)
        {
            printf("That is not on the board!\n");
            break;
        }
        if (board[row4][col4] == 'o')
        {
            printf("That spot is occupied!");
            break;
        }
        if(board[row4][col4] == 'x')
        {
            printf("checking if = 'o' runs\n");
            printf("col2-col1 == 1 runs\n");
            if(col4-col3 == 1 ) /*jumping from left ro right */
            {
                row4++; /*checking down 1 right 1r*/
                col++;
                if(spotEmpty(row4,col4)==1 )
                {
                    row4--; /*back to original */ 
                    col4--;
                    removePiece(row4,col4);
                    removePiece(row3,col3);
                    row4++; /* down 1 right 1 */
                    col4++;
                    createPiece(row4,col4,computer);
                    printf("you removed a piece!\n");
                    break;
                }
            }
            if(col4-col3 == -1)
            {
                row4++; /*checking down 1 left 1 */ 
                col4--;
                if((spotEmpty(row4,col4))==1)
                {
                    row4--; /* revert back to original */
                    col4++;
                    removePiece(row4,col4);
                    removePiece(row3,col3);
                    row4++; /* down 1 left 1 of x piece that is being eaten */
                    col4--;
                    createPiece(row4,col4,computer);
                    printf("you removed a piece!\n");
                    break;
                }
            }
        }
        else
        {
            removePiece(rowdf,coldf);
            createPiece(row4,col4,computer);
            break;
        }
    }
        

}
    

