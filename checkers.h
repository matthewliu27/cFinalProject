/*
*     * checkers.h
*         */
  
#ifndef checkers
#define checkers
  
#define boardSize 8
int row,col,row2,col2; /* for user*/
int row3,col3,row4,col4; /*for cpu*/
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
                 
