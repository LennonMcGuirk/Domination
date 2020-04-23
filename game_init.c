#include "game_init.h"

//Set Invalid Squares (where it is not possible to place stacks)
void set_invalid(square * s)
{
    s->type = INVALID;
    s->stack = NULL;
    s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
void set_empty(square * s)
{
    s->type = VALID;
    s->stack = NULL;
    s->num_pieces = 0;
}

//Set squares  with a GREEN piece
void set_green(square * s)
{
    s->type = VALID;
    s->stack = (piece *) malloc (sizeof(piece));
    s->stack->p_color = GREEN;
    s->stack->next = NULL;
    s->num_pieces = 1;
}

//Set squares with a RED piece
void set_red(square * s)
{
    s->type = VALID;
    s->stack = (piece *) malloc (sizeof(piece));
    s->stack->p_color = RED;
    s->stack->next = NULL;
    s->num_pieces = 1;
}

//Function to initialize the players in the game
void initialize_players(player players[PLAYERS_NUM])
{
    //Initializes the choice in the menu.
    int choice;

    //Takes in both players names.
    for (int i = 0; i < PLAYERS_NUM; i++)
    {
        printf("Insert players %d name:\n", i+1);
        scanf("%s", &players[i].name);
    }

    //Gives the choice of colour to player 1.
    printf("%s, please choose a colour, Red (1) or Green (2):\n", players[0].name);
    scanf("%d", &choice);

    //Allocates the colours.
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
    //Calls to allocate misc values.
    allocation(players);
}

void allocation(player players[PLAYERS_NUM])
{
    players[0].reserved_count = 0;
    players[1].reserved_count = 0;
    players[0].removed = 0;
    players[1].removed = 0;
    players[0].captured = 0;
    players[1].captured = 0;
    players[0].owned = 18;
    players[1].owned = 18;
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
