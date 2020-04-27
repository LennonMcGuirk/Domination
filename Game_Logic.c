#include "Game_Logic.h"

//Function to remove the last piece of the stack
piece * pop(piece *p1, player players[PLAYERS_NUM], int i)
{
    piece * temp = p1;
    piece * prev;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;

    if(temp->p_color == players[i].player_color)
    {
        players[i].reserved_count++;
    }
    else
    {
        players[i].removed++;
    }

    prev->next = temp->next;
    free(temp);
    return p1;
}

piece * pop2(piece *p1)
{
    piece * temp = p1, *prev;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next=NULL;
    return p1;
}

//Function to merge the stacks.
piece * push(piece *p1, piece * top)
{
    while(p1->next != NULL)
    {
        p1 = p1->next;
    }

    piece * curr = top;
    top = malloc(sizeof(piece));
    top->p_color = p1->p_color;
    top->next = curr;
    return top;
}

//Function to runs through the moves and check that its a legal move.
void requestMove(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i)
{
    //Initialises the variables for the co-ordinates as well as the boolean check to keep track of if the input fails the check.
    int inputX, inputY, outputX, outputY;
    bool check;
    bool check2;
    printf("\n%s please enter the co-ordinates of the piece you would like to move:\n", players[i].name);
    scanf("%d %d", &inputX, &inputY);

    check = false;

    //Checks the input co-ordinates and if they are valid.
    if((board[inputX][inputY].type == VALID) && (board[inputX][inputY].stack->p_color == players[i].player_color) && (board[inputX][inputY].stack != NULL) && (board[inputX][inputY].num_pieces != 0))
    {
        check = true;
    }

    //Otherwise, loops until valid input is put in.
    while(!check)
    {
        puts("Please only choose squares that you currently control.");
        scanf("%d %d", &inputX, &inputY);

        if((board[inputX][inputY].type == VALID) && (board[inputX][inputY].stack->p_color == players[i].player_color) && (board[inputX][inputY].stack != NULL) && (board[inputX][inputY].num_pieces != 0))
        {
            check = true;
        }
    }

    //If passed through first check takes in the co-ordinates of the second space
    if(check) {
        check2 = false;
        printf("\nPlease enter the co-ordinates of the space you could like to move to:\n");
        scanf("%d %d", &outputX, &outputY);

        //Different input possibilities are checked

        //For moving up the board.
        if ((inputX > outputX) && ((inputX - outputX) <= board[inputX][inputY].num_pieces) && (inputY == outputY) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
        {
            check2 = true;
        }

        //For moving down the board.
        if ((outputX > inputX) && ((outputX - inputX) <= board[inputX][inputY].num_pieces) && (inputY == outputY) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
        {
            check2 = true;
        }

        //For moving right on the board.
        if ((inputY > outputY) && ((inputY - outputY) <= board[inputX][inputY].num_pieces) && (inputX == outputX) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
        {
            check2 = true;
        }

        //For moving left on the board.
        if ((outputY > inputY) && ((outputY - inputY) <= board[inputX][inputY].num_pieces) && (inputX == outputX) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
        {
            check2 = true;
        }

        //Otherwise equal remains false until valid co-ordinates are input.
        else
        {
            while (!check2)
            {
                check2 = false;
                puts("Please only choose squares within reach of your stack.");
                scanf("%d %d", &outputX, &outputY);
                if ((inputX > outputX) && ((inputX - outputX) <= board[inputX][inputY].num_pieces) && (inputY == outputY) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
                {
                    check2 = true;
                }

                if ((outputX > inputX) && ((outputX - inputX) <= board[inputX][inputY].num_pieces) && (inputY == outputY) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
                {
                    check2 = true;
                }

                if ((inputY > outputY) && ((inputY - outputY) <= board[inputX][inputY].num_pieces) && (inputX == outputX) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
                {
                    check2 = true;
                }

                if ((outputY > inputY) && ((outputY - inputY) <= board[inputX][inputY].num_pieces) && (inputX == outputX) && (0 <= outputX && outputX <= 7) && (0 <= outputY && outputY <= 7))
                {
                    check2 = true;
                }
            }
        }

        //if equal is still true, push and pop are called.
        if (check2)
        {
                //Code for moving to an empty space.
                if (board[outputX][outputY].stack == NULL)
                {
                    //Sets the new size for num pieces.
                    board[outputX][outputY].num_pieces = board[inputX][inputY].num_pieces;

                    while (board[inputX][inputY].num_pieces != 0)
                    {
                        //Pushes the stack from the input square to the desires output square one by one.
                        board[outputX][outputY].stack = push(board[inputX][inputY].stack, board[outputX][outputY].stack);
                        if(board[inputX][inputY].stack->next != NULL)
                        {
                            pop2(board[inputX][inputY].stack);
                        }
                        board[inputX][inputY].num_pieces--;
                    }
                }

                    //Code for moving to another players space.
                else if (board[outputX][outputY].stack != NULL && board[outputX][outputY].stack->p_color != board[inputX][inputY].stack->p_color)
                {
                    //Changes the relevant captured and owned count.
                    if (players[0].name == players[i].name)
                    {
                        players[0].captured++;
                        players[1].owned--;
                    }

                    else if (players[1].name == players[i].name)
                    {
                        players[1].captured++;
                        players[0].owned--;
                    }

                    //Alters the output piece count.
                    board[outputX][outputY].num_pieces += board[inputX][inputY].num_pieces;

                    //Pushes the bottom node of the input stack to the top of the output stack until the piece count for input reaches 0.
                    while (board[inputX][inputY].num_pieces != 0)
                    {
                        board[outputX][outputY].stack = push(board[inputX][inputY].stack, board[outputX][outputY].stack);
                        if(board[inputX][inputY].stack->next != NULL)
                        {
                            pop2(board[inputX][inputY].stack);
                        }
                        board[inputX][inputY].num_pieces--;
                    }
                }

                    //Code for moving to a space of the same colour.
                else if (board[outputX][outputY].stack != NULL && board[outputX][outputY].stack->p_color == board[inputX][inputY].stack->p_color)
                {
                    //Changes the relevant owned count.
                    if (players[0].name == players[i].name)
                    {
                        players[0].owned--;
                    }

                    else if (players[1].name == players[i].name)
                    {
                        players[1].owned--;
                    }

                    //Changes the output piece count.
                    board[outputX][outputY].num_pieces += board[inputX][inputY].num_pieces;

                    //Pushes the bottom node of the input stack to the top of the output stack until the piece count for input reaches 0.
                    while (board[inputX][inputY].num_pieces != 0)
                    {
                        board[outputX][outputY].stack = push(board[inputX][inputY].stack, board[outputX][outputY].stack);
                        if(board[inputX][inputY].stack->next != NULL)
                        {
                            pop2(board[inputX][inputY].stack);
                        }
                        board[inputX][inputY].num_pieces--;
                    }
                }

                //Sets the original space to null.
                set_empty(&board[inputX][inputY]);

                //Checks if the stack is over 5 pieces and removes the appropriate amount.
                while (board[outputX][outputY].num_pieces > 5)
                    {
                        board[outputX][outputY].stack = pop(board[outputX][outputY].stack, players, i);
                        board[outputX][outputY].num_pieces--;
                    }
                print_board(board);
        }
    }
}




//Function to place reserved pieces on the board.
void placeReserve(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int i)
{
    bool check3 = false;
    int X, Y;
    puts("Please choose a currently empty square.");
    scanf("%d %d", &X, &Y);

    //Checks if the space is valid.
    if(board[X][Y].num_pieces == 0 && board[X][Y].stack == NULL && board[X][Y].type == VALID)
    {
        check3 = true;

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
    while(!check3)
    {
        puts("Sorry that is not a valid square, please choose a valid space");
        scanf("%d %d", &X, &Y);

        if(board[X][Y].num_pieces == 0 && board[X][Y].stack == NULL && board[X][Y].type == VALID)
        {
            check3 = true;
            if (players[i].player_color == GREEN)
            {
                set_green(&board[X][Y]);
                players[i].reserved_count--;
                print_board(board);
            }

            if (players[i].player_color == RED)
            {
                set_red(&board[X][Y]);
                players[i].reserved_count--;
                print_board(board);
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
        printf( "Square is empty.\n\n" );
    }

    else
    {
        printf( "The list is:\n" );

        //While not at the end of the list
        while ( currentPtr != NULL ) {

            //Prints the appropriate colour
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

//Function to check if the winning conditions have been reached.
void winCheck(player players[PLAYERS_NUM], int i, int turnCount)
{
    if(players[i].owned == 0 && players[i].reserved_count == 0)
    {
        //Determines which player has reached a zero count first
        if(players[i].name == players[0].name)
        {
            winningState(players, 1, turnCount);
            losingState(players, 0);
            //Exits the game
            exit(1);
        }
        if(players[i].name == players[1].name)
        {
            winningState(players, 0, turnCount);
            losingState(players, 1);
            exit(1);
        }
    }
}