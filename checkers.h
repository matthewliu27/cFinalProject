/*
*     * checkers.h
*         */
  
#ifndef checkers
#define checkers
  
#define boardSize 8

int row,col;

char user;
char computer;
char board[boardSize][boardSize];
 
void initBoard(void);
   
void drawBoard(void);
     
int goFirst(void);

void startGame(void);

void computerMove(void);
           
void playerMove(void);
void movePiece(int row1, int row2);
void movePieceCPU(int row1, int row2);

void removePiece(int a, int b);

void createPiece(int a, int b, char c);

int spotEmpty(int a, int b);


int border(int a, int b);

int checkPieces(char a);
#endif
                 
