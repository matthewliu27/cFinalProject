/*
*     * checkers.h
*         */
  
#ifndef checkers
#define checkers
  
#define boardSize 8
int row,col,row2,col2; /* for player1*/
int row3,col3,row4,col4; /*for player2*/
char player1;
char player2;
char board[boardSize][boardSize];
 
void initBoard(void);
   
void drawBoard(void);

void startGame(void);

void player2Move(void);
           
void playerMove(void);
void player1movePiece(int row1, int row2);
void player2movePiece(int row1, int row2);

void removePiece(int a, int b);

void createPiece(int a, int b, char c);

int spotEmpty(int a, int b);


int border(int a, int b);

int checkPieces(char a);
#endif
                 
