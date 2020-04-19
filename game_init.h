
#ifndef DOMINATIONPROJECT_GAME_INIT_H
#define DOMINATIONPROJECT_GAME_INIT_H

#endif //DOMINATIONPROJECT_GAME_INIT_H

#include<stdbool.h>

#define BOARD_SIZE 8
#define PLAYERS_NUM 2
#define MAX_CHAR 20

//colors that a piece can have
typedef enum color
{
    RED,
    GREEN,
}color;

// Square types
//INVALID: squares that are on the sides and where no piece can be placed
//VALID: squares where it is possible to place a piece or a stack
typedef enum square_type
{
    VALID,
    INVALID
}square_type;

//Player
typedef struct player
{
    //the color associated with the player
    color player_color;
    char name[MAX_CHAR];

    struct square* reserve;

    int captured;

    int owned;
}player;

// A piece
typedef struct piece
{
    //the color associated with a piece
    color p_color;
    // This is a pointer to the next pieces
    // to create a stack. For this lab you do not have to think too much about it.
    struct piece * next;

}piece;

// A Square of the board
typedef struct square
{
    // type of the square (VALID/INVALID)
    square_type type;

    //the piece or the top piece on the stack
    piece * stack;

    //number of pieces on the square
    int num_pieces;

}square;

//Function to create the players
void initialize_players(player players[PLAYERS_NUM]);

//Function to take the move of a player
void requestMove(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE]);

//Function to check valid choice
int moveCheck1(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int x, int y, int i, bool equal);

//Function to check if the chosen spot is a valid choice
int moveCheck2(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], int inX, int inY, int ouX, int ouY, bool equal);



//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);


