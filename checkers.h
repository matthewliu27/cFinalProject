/* 
 * checkers.h
 */

#ifndef checkers
#define checkers

#define boardSize 8

char board[boardSize][boardSize];

void initBoard(void);

void drawBoard(void);

char user;
char computer;

int goFirst(void);

#endif
