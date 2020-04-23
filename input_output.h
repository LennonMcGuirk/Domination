
#ifndef DOMINATIONPROJECT_INPUT_OUTPUT_H
#define DOMINATIONPROJECT_INPUT_OUTPUT_H

#include "Libraries.h"
#include "game_init.h"

//Function prototypes.
void print_board(square board[BOARD_SIZE][BOARD_SIZE]);

void printMenu(player players[PLAYERS_NUM], int i);

void printStats(player players[PLAYERS_NUM], int i);

void winningState(player players[PLAYERS_NUM], int i, int turns);

void losingState(player players[PLAYERS_NUM], int i);

#endif //DOMINATIONPROJECT_INPUT_OUTPUT_H