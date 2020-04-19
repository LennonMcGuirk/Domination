#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "game_init.h"

void initialize_players(player players[PLAYERS_NUM])
{
    int choice;

    for (int i = 0; i < PLAYERS_NUM; i++)
    {
        printf("Insert players %d number\n", i+1);
        scanf("%s", &players[i].name);
    }

    printf("%s, please choose a colour, Red (1) or Green (2):\n", players[0].name);
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("%s will be red and %s will be green.", players[0].name, players[1].name);
        players[0].player_color = RED;
        players[1].player_color = GREEN;
    }
    if (choice == 2)
    {
        printf("%s will be red and %s will be green.\n", players[1].name, players[0].name);
        players[0].player_color = GREEN;
        players[1].player_color = RED;
    }

    players[0].reserve = 0;
    players[1].reserve = 0;
    players[0].captured = 0;
    players[1].captured = 0;
    players[0].owned = 18;
    players[1].owned = 18;
}

void requestMove(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE])
{
    int inputX, inputY, outputX, outputY;
    bool equal = true;

    while(players[0].owned != 0 || players[1].owned != 0)
    {
        for(int i = 0; i < PLAYERS_NUM; i++)
        {
            printf("%s please enter the co-ordinates of the piece you would like to move:\n", players[i].name);
            scanf("%d %d", &inputX, &inputY);
            moveCheck1(players, board, inputX, inputY, i, equal);
            printf("Please enter the co-ordinates of the space you could like to move to:\n");
            scanf("%d %d", &outputX, &outputY);
            moveCheck2(players, board, inputX, inputY, outputX, outputY, equal);

            if(equal = true)
            {

            }
        }
    }
}

int moveCheck1(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int x, int y, int i, bool equal)
{
    if(board[x][y].type == VALID && board[x][y].stack->p_color == players[i].player_color && board[x][y].stack != NULL)
    {
        equal = true;
        return(equal);
    }

    else if(board[x][y].type == INVALID || board[x][y].stack->p_color != players[i].player_color || board[x][y].num_pieces == 0 || board[x][y].stack == NULL)
    {
        equal = false;
        puts("Please only choose squares that you currently control.\n");
        scanf("%d %d", &x, &y);
        moveCheck1(players, board, x, y, i, equal);
    }
}

int moveCheck2(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int inX, int inY, int ouX, int ouY, bool equal)
{
    if((inX > ouX && (inX-ouX) <= board[inX][inY].num_pieces) && (inY == ouY))
    {
        equal = true;
        return(equal);
    }

    if((ouX > inX && (ouX-inX) <= board[inX][inY].num_pieces) && (inY == ouY))
    {
        equal = true;
        return(equal);
    }

    if((inY > ouY && (inY-ouY) <= board[inX][inY].num_pieces) && (inX == ouX))
    {
        equal = true;
        return(equal);
    }

    if((ouY > inY && (ouY-inY) <= board[inX][inY].num_pieces) && (inX == ouX))
    {
        equal = true;
        return(equal);
    }

    else
    {
        equal = false;
        puts("Please only choose squares within reach of your stack.\n");
        scanf("%d %d", &ouX, &ouY);
        moveCheck2(players, board, inX, inY, ouX, ouY, equal);
    }
}



//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s)
{
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s)
{
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s)
{
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s)
{
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE])
{

    for(int i=0; i< BOARD_SIZE; i++)
    {
        for(int j=0; j< BOARD_SIZE; j++)
        {
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else
            {
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else
                {
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }


    }


}

