#include "Libraries.h"
#include "input_output.h"
#include "Game_Logic.h"

int main() {

    int choice = 0, turnCount = 0;
    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);

    while(players[0].owned != 0 || players[1].owned != 0)
    {
        printf("Player %s has %d tokens remaining.\nYou have removed %d pieces and %d pieces in reserve.\n\n", players[0].name, players[0].owned, players[0].removed, players[0].reserved_count);
        printf("Player %s has %d tokens remaining.\nYou have removed %d pieces and %d pieces in reserve.\n", players[1].name, players[1].owned, players[1].removed, players[1].reserved_count);
        turnCount++;
        for(int i = 0; i < PLAYERS_NUM; i++)
        {
            printf("\n%s what would you like to do?\n"
                   "1: Make a move.\n"
                   "2: Place a reserved piece.\n"
                   "3: End the program early.\n", players[i].name);
            scanf("%d", &choice);

            if(choice == 1)
            {
                requestMove(players, board, i);
            }

            if(choice == 2 && players[i].reserved_count == 0)
            {
                printf("\nSorry %s you dont seem to have any pieces in reserve.\nIt is assumed you wish to make a move.\n", players[i].name);
                requestMove(players, board, i);
            }

            if(choice == 2 && players[i].reserved_count > 0)
            {
                placeReserve(players, board, i);
            }

            if(choice == 3)
            {
                exit(1);
            }
        }
    }

    if(players[0].owned == 0 && players[1].captured == 18)
    {
        printf("\n%s is the winner.\n", players[1].name);
        printf("\n%s captured %d stacks and removed %d pieces from the board in just %d turns.\n", players[1].name, players[1].captured, players[1].removed, turnCount);
        printf("\n%s captured %d stacks and removed %d pieces from the board.\n", players[0].name, players[0].captured, players[0].removed);
    }

    if(players[1].owned == 0 && players[0].captured == 18)
    {
        printf("\n%s is the winner.\n", players[0].name);
        printf("\n%s captured %d stacks and removed %d pieces from the board in just %d turns.\n", players[0].name, players[0].captured, players[0].removed, turnCount);
        printf("\n%s captured %d stacks and removed %d pieces from the board.\n", players[1].name, players[1].captured, players[1].removed);
    }

    return 0;
}
