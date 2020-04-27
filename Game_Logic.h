#ifndef DOMINATIONPROJECT_GAME_LOGIC_H
#define DOMINATIONPROJECT_GAME_LOGIC_H

#include "input_output.h"
#include "Libraries.h"

//Function prototypes
piece * push(piece *p1, piece *p2);

piece * pop(piece *p1, player players[PLAYERS_NUM], int i);

piece * pop2(piece *p1);

void requestMove(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i);

void placeReserve(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i);

void printList( piece * currentPtr );

void winCheck(player players[PLAYERS_NUM], int i, int turnCount);

#endif //DOMINATIONPROJECT_GAME_LOGIC_H
