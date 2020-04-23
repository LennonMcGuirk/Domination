#ifndef DOMINATIONPROJECT_GAME_LOGIC_H
#define DOMINATIONPROJECT_GAME_LOGIC_H

#include "input_output.h"
#include "Libraries.h"

//Function prototypes
piece * push(piece* p1, piece *top);

piece * pop(piece *top, player players[PLAYERS_NUM], int i);

void requestMove(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i);

void placeReserve(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i);

void printList( piece * currentPtr );

#endif //DOMINATIONPROJECT_GAME_LOGIC_H
