/*
*     * checkers.h
*         */

#ifndef checkers
#define checkers

#define boardSize 8
int row1, col1, row2, col2; /* for player1*/
int row3, col3, row4, col4; /*for player2*/

char player1; /*player 1 decleration, set it to x in main */
char player2; /*player 2 decleration, set it to o in main */
char player1King;
char player2King;

char board[boardSize][boardSize]; /*set boardsize 8x8 */

void initBoard(void); /* init board*/

void drawBoard(void); /* draw board*/

void startGame(void); /*Play game */

/* Player move functions */
void playerMove(void); /*player1 choose piece */
void player2Move(void); /*player2 choose piece*/
void player1movePiece(int row1, int row2); /*player1 move piece */
void player2movePiece(int row1, int row2); /*player2 move piece*/

void removePiece(int a, int b); /*sets boardspot to ' ' */

void createPiece(int a, int b, char c); /* places x or o in board spot */

int spotEmpty(int a, int b); /* check if boardspot = ' ' */

int border(int a, int b); /* prevents choices that are not on board  0<=row<=8 0<=col<=8 */

int checkPieces(char a); /* Checks for win */
#endif
