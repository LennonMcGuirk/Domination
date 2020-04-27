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
            //Checks if a player has reached the winning conditions yet.
            winCheck(players, i, turnCount);
            //Prints the stats of the current player and the options.
            printStats(players, i);
            printMenu(players, i);
            scanf("%d", &choice);

            //Choice for if the player can make a move and currently owns a piece on the board.
            if(choice == 1 && (players[i].owned !=0))
            {
                requestMove(players, board, i);
            }

            //Choice for if the player only has pieces in reserve left.
            if(choice == 1 && players[i].owned == 0 && players[i].reserved_count != 0)
            {
                printf("Sorry %s it seems you dont control anything on the board.\n", players[i].name);
                placeReserve(players, board, i);
            }

            //Choice to place pieces in reserve but has none.
            if(choice == 2 && players[i].reserved_count == 0)
            {
                printf("\nSorry %s you dont seem to have any pieces in reserve.\nIt is assumed you wish to make a move.\n", players[i].name);
                requestMove(players, board, i);
            }

            //Choice to place pieces in reserve.
            if(choice == 2 && players[i].reserved_count > 0)
            {
                placeReserve(players, board, i);
            }

            //Choice to see a stacks build.
            if(choice == 3)
            {
                int X, Y;
                puts("Please choose the stack you would like to see.");
                scanf("%d %d", &X, &Y);
                printList(board[X][Y].stack);
                requestMove(players, board, i);
            }

            //Choice to exit game.
            if(choice == 4)
            {
                exit(1);
            }
        }
    }
}
