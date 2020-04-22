#include "Game_Logic.h"

piece * push(piece* p1, piece *top)
{
    piece * curr = top;
    top = malloc(sizeof(piece));
    top->p_color = p1->p_color;
    top->next = curr;
    return top;
}

piece * pop(piece *top, player players[PLAYERS_NUM], int i)
{
    piece * curr;
    curr = top->next;
    while(curr->next != NULL)
    {
        top = curr;
        curr = curr->next;
    }

    if(players[0].name == players[i].name)
    {
        if (top->p_color == players[0].player_color)
        {
            players[0].reserved_count ++ ;
        }

        else
        {
            players[0].removed += 1;
        }
    }

    else if(players[1].name == players[i].name)
    {
        if (top->next->p_color == players[1].player_color)
        {
            players[1].reserved_count ++;
        }

        else
        {
            players[1].removed++;
        }
    }

    free(top->next);
    top->next = NULL;
}

void requestMove(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i)
{
    int inputX, inputY, outputX, outputY;
    bool equal = false;
    printf("\n%s please enter the co-ordinates of the piece you would like to move:\n", players[i].name);
    scanf("%d %d", &inputX, &inputY);
    if(board[inputX][inputY].type == VALID && board[inputX][inputY].stack->p_color == players[i].player_color && board[inputX][inputY].stack != NULL)
    {
        equal = true;
    }

    while(!equal)
    {
        puts("Please only choose squares that you currently control.");
        scanf("%d %d", &inputX, &inputY);
        if(board[inputX][inputY].type == VALID && board[inputX][inputY].stack->p_color == players[i].player_color && board[inputX][inputY].stack != NULL)
        {
            equal = true;
        }
        else
        {
            equal = false;
        }
    }

    if(equal)
    {
        equal = false;
        printf("\nPlease enter the co-ordinates of the space you could like to move to:\n");
        scanf("%d %d", &outputX, &outputY);

        if((inputX > outputX) && ((inputX-outputX) <= board[inputX][inputY].num_pieces) && (inputY == outputY) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
        {
            equal = true;
        }

        if((outputX > inputX) && ((outputX-inputX) <= board[inputX][inputY].num_pieces) && (inputY == outputY) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
        {
            equal = true;
        }

        if((inputY > outputY) && ((inputY-outputY) <= board[inputX][inputY].num_pieces) && (inputX == outputX) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
        {
            equal = true;
        }

        if((outputY > inputY) && ((outputY-inputY) <= board[inputX][inputY].num_pieces) && (inputX == outputX) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
        {
            equal = true;
        }

        else
        {
            while(!equal)
            {
                equal = false;
                puts("Please only choose squares within reach of your stack.");
                scanf("%d %d", &outputX, &outputY);
                if((inputX > outputX) && ((inputX-outputX) <= board[inputX][inputY].num_pieces) && (inputY == outputY) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
                {
                    equal = true;
                }

                if((outputX > inputX) && ((outputX-inputX) <= board[inputX][inputY].num_pieces) && (inputY == outputY) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
                {
                    equal = true;
                }

                if((inputY > outputY) && ((inputY-outputY) <= board[inputX][inputY].num_pieces) && (inputX == outputX) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
                {
                    equal = true;
                }

                if((outputY > inputY) && ((outputY-inputY) <= board[inputX][inputY].num_pieces) && (inputX == outputX) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
                {
                    equal = true;
                }
            }
        }

        if (equal)
        {
            if(board[outputX][outputY].stack == NULL)
            {
                board[outputX][outputY].num_pieces = board[inputX][inputY].num_pieces;

                while(board[inputX][inputY].num_pieces != 0)
                {
                    printf("We have reached here");
                    board[outputX][outputY].stack = push(board[inputX][inputY].stack, board[outputX][outputY].stack);
                    board[inputX][inputY].num_pieces --;
                }

            }

            else if(board[outputX][outputY].stack != NULL && board[outputX][outputY].stack->p_color != board[inputX][inputY].stack->p_color)
            {
                if(players[0].name == players[i].name)
                {
                    players[0].captured ++;
                    players[1].owned --;
                }

                else if(players[1].name == players[i].name)
                {
                    players[1].captured ++;
                    players[0].owned --;
                }

                board[outputX][outputY].num_pieces += board[inputX][inputY].num_pieces;
                while(board[inputX][inputY].num_pieces != 0)
                {
                    board[outputX][outputY].stack = push(board[inputX][inputY].stack, board[outputX][outputY].stack);
                    board[inputX][inputY].num_pieces --;
                }
            }

            else if(board[outputX][outputY].stack != NULL && board[outputX][outputY].stack->p_color == board[inputX][inputY].stack->p_color)
            {
                if(players[0].name == players[i].name)
                {
                    players[0].owned --;
                }

                else if(players[1].name == players[i].name)
                {
                    players[1].owned --;
                }

                board[outputX][outputY].num_pieces += board[inputX][inputY].num_pieces;
                while(board[inputX][inputY].num_pieces != 0)
                {
                    board[outputX][outputY].stack = push(board[inputX][inputY].stack, board[outputX][outputY].stack);
                    board[inputX][inputY].num_pieces --;
                }
            }

            else if(board[outputX][outputY].stack == NULL)
            {
                board[outputX][outputY].num_pieces = board[inputX][inputY].num_pieces;

                while(board[inputX][inputY].num_pieces != 0)
                {
                    printf("We have reached here");
                    board[outputX][outputY].stack = push(board[inputX][inputY].stack, board[outputX][outputY].stack);
                    board[inputX][inputY].num_pieces --;
                }

            }

            set_empty(&board[inputX][inputY]);

            if(board[outputX][outputY].num_pieces > 5)
            {
                while(board[outputX][outputY].num_pieces > 5)
                {
                    pop(board[outputX][outputY].stack, players, i);
                    board[outputX][outputY].num_pieces --;
                }
            }

            print_board(board);
        }
    }
}

void placeReserve(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i)
{
    bool equal = false;
    int X, Y;
    puts("Please choose a currently empty square.");
    scanf("%d %d", &X, &Y);

    if(board[X][Y].num_pieces == 0 && board[X][Y].stack == NULL && board[X][Y].type == VALID)
    {
        equal = true;

        if (players[i].player_color == GREEN)
        {
                set_green(&board[X][Y]);
                players[i].reserved_count--;
                players[i].owned ++;
                print_board(board);
        }

        if (players[i].player_color == RED)
        {
            set_red(&board[X][Y]);
            players[i].reserved_count--;
            players[i].owned ++;
            print_board(board);
        }
    }


    while(!equal)
    {
        puts("Sorry that is not a valid square, please choose a valid space");
        puts("Please choose a currently empty square.");
        scanf("%d %d", &X, &Y);

        if(board[X][Y].num_pieces == 0 && board[X][Y].stack == NULL && board[X][Y].type == VALID)
        {
            equal = true;

            while (equal)
            {
                if (players[i].player_color == GREEN)
                {
                    equal = false;
                    set_green(&board[X][Y]);
                    players[i].reserved_count--;
                    print_board(board);
                }

                if (players[i].player_color == RED)
                {
                    equal = false;
                    set_red(&board[X][Y]);
                    players[i].reserved_count--;
                    print_board(board);
                }
            }
        }
    }
}

void printList( piece * currentPtr )
{
    /* if list is empty */
    if ( currentPtr == NULL ) {
        printf( "List is empty.\n\n" );
    } /* end if */
    else {
        printf( "The list is:\n" );

        /* while not the end of the list */
        while ( currentPtr != NULL ) {

            if(currentPtr->p_color == 1)
            {
                puts("GREEN");
            }
            if(currentPtr->p_color == 0)
            {
                puts("RED");
            }
            currentPtr = currentPtr->next;
        } /* end while */
    } /* end else */
} /* end function printList */