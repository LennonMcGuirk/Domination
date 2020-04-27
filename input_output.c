#include <stdio.h>
#include "input_output.h"
/* Function to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n              ****** The Board ******\n");
    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("|     ");
                else
                {
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| %d-G ", board[i][j].num_pieces);
                    else printf("| %d-R ", board[i][j].num_pieces);
                }
            }
            else
                printf("| --- ");
        }
        printf("|\n");
    }
}

//Function to print the menu of options for each player.
void printMenu(player players[PLAYERS_NUM], int i)
{
    puts("\nWhat would you like to do?\n"
           "1: Make a move.\n"
           "2: Place a reserved piece.\n"
           "3: See the composition of a specific stack.\n"
           "4: End the program early.\n");
}

//Function to print the stats of each player.
void printStats(player players[PLAYERS_NUM], int i)
{
    printf("\n----%s's Move----\n", players[i].name);
    printf("\n%s, you have %d tokens remaining.\nYou have removed %d pieces and %d pieces in reserve.\n\n", players[i].name, players[i].owned, players[i].removed, players[i].reserved_count);
}

//Function to print the winner of the game.
void winningState(player players[PLAYERS_NUM], int i, int turns)
{
    printf("\n%s is the winner.\n", players[i].name);
    printf("\n%s captured %d stacks and removed %d pieces from the board in just %d turns.\n", players[i].name, players[i].captured, players[i].removed, turns);
}

//Function to print the loser of the game.
void losingState(player players[PLAYERS_NUM], int i)
{
    printf("%s captured %d stacks and removed %d pieces from the board.\n", players[i].name, players[i].captured, players[i].removed);
}