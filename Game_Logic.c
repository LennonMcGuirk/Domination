#include "Game_Logic.h"

//Function to merge the stacks.
piece * push(piece* p1, piece *top)
{
    piece * curr = top;
    top = malloc(sizeof(piece));
    top->p_color = p1->p_color;
    top->next = curr;
    return top;
}

//Function to remove the last piece of the stack
piece * pop(piece *top, player players[PLAYERS_NUM], int i)
{
    piece * curr;
    curr = top->next;
    while(curr->next != NULL)
    {
        top = curr;
        curr = curr->next;
    }

    /*Checks whether the piece being removed belongs to the player in control of the stack
     * and adds to either the reserve or removed count.*/
    if(players[0].name == players[i].name)
    {
        if (top->p_color == players[0].player_color)
        {
            players[0].reserved_count ++;
        }

        else
        {
            players[0].removed ++;
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

//Function to runs through the moves and check that its a legal move.
void requestMove(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i)
{
    //Initialises the variables for the co-ordinates as well as the boolean equal to keep track of if the input fails the check.
    int inputX, inputY, outputX, outputY;
    bool equal = false;
    printf("\n%s please enter the co-ordinates of the piece you would like to move:\n", players[i].name);
    scanf("%d %d", &inputX, &inputY);

    //Checks the input co-ordinates and if they are valid.
    if(board[inputX][inputY].type == VALID && board[inputX][inputY].stack->p_color == players[i].player_color && board[inputX][inputY].stack != NULL)
    {
        equal = true;
    }

    //Otherwise, loops until valid input is put in.
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

    //If passed through first check takes in the co-ordinates of the second space
    if(equal)
    {
        equal = false;
        printf("\nPlease enter the co-ordinates of the space you could like to move to:\n");
        scanf("%d %d", &outputX, &outputY);

        //Different input possibilities are checked
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

        //Otherwise equal remains false until valid co-ordinates are input.
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

        //if equal is still true, push and pop are called.
        if (equal)
        {
            //Code for moving to an empty space.
            if(board[outputX][outputY].stack == NULL)
            {
                board[outputX][outputY].num_pieces = board[inputX][inputY].num_pieces;

                while(board[inputX][inputY].num_pieces != 0)
                {
                    board[outputX][outputY].stack = push(board[inputX][inputY].stack, board[outputX][outputY].stack);
                    board[inputX][inputY].num_pieces --;
                }

            }

            //Code for moving to another players space.
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

            //Code for moving to a space of the same colour.
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

            //Sets the original space to null.
            set_empty(&board[inputX][inputY]);

            //Checks if the stack is over 5 pieces and removes the appropriate amount.
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

//Function to place reserved pieces on the board.
void placeReserve(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i)
{
    bool equal = false;
    int X, Y;
    puts("Please choose a currently empty square.");
    scanf("%d %d", &X, &Y);

    //Checks if the space is valid.
    if(board[X][Y].num_pieces == 0 && board[X][Y].stack == NULL && board[X][Y].type == VALID)
    {
        equal = true;

        //Sets the empty square to a stack of 1 colour depending on players colour.
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

    //Otherwise continues until a valid square is chosen.
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

//Function to print the list of the stack.
void printList( piece * currentPtr )
{
    //Checks if list is empty
    if ( currentPtr == NULL )
    {
        printf( "List is empty.\n\n" );
    }

    else
    {
        printf( "The list is:\n" );

        //While not at the end of the list
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
        }
    }
}