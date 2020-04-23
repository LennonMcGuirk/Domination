#include "Libraries.h"
#include "input_output.h"
#include "Game_Logic.h"

int main() {

    //Initialises the integer variables to count the overall turns and the choice from menu.
    int choice = 0, turnCount = 0;

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    //Function calls to initialise the original game state.
    initialize_players(players);

    initialize_board(board);

    print_board(board);

    //Allows for a move to be made provided neither player has no pieces remaining.
    while(players[0].owned != 0 || players[1].owned != 0)
    {
        //I am only counting a turn as a full rotation i.e both players have to make a move for 1 turn to be counted.
        turnCount++;

        //Runs through each players turn.
        for(int i = 0; i < PLAYERS_NUM; i++)
        {
            printStats(players, i);
            printMenu(players, i);
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
                int X, Y;
                puts("Please choose the stack you would like to see.");
                scanf("%d %d", &X, &Y);
                printList(board[X][Y].stack);
                requestMove(players, board, i);
            }

            if(choice == 4)
            {
                exit(1);
            }
        }
    }

    //Prints the winning state depending on who reaches 0 first.
    if(players[0].owned == 0 && players[0].reserved_count == 0 && players[1].captured == 18)
    {
        winningState(players, 1, turnCount);
        losingState(players, 0);
    }

    if(players[1].owned == 0 && players[1].reserved_count == 0 && players[0].captured == 18)
    {
        winningState(players, 0, turnCount);
        losingState(players, 1);
    }

    return 0;
}
