// decleration
void debug(char *board);
void check(char *board);
void specific_check();

// import files
#include "functions.h"

// variables
int total;
extern int white_pawn_moves[4];
extern int black_pawn_moves[4];
extern int knight_moves[8];
extern int bishop_moves[13];
extern int rook_moves[15];
extern int queen_moves[27];
extern int king_moves[8];

void debug(char *board)
{
    for (int i = 0; i < 64; i++)
    {
        reset_moves();
        move_generation(board, i);
        specific_check();
        // check(board);
        // printf("for the %i square\n\n", i);
    }

    printf("the total amount of moves are: %i\n", total);
}

void check(char *board)
{
    // check_white_pawn(board);
    // check_black_pawn(board);
    // check_bishop(board);
    // check_knight(board);
    // check_rook(board);
    // check_queen(board);
    check_king(board);
}

void specific_check()
{
    int moves = 0;

    for (int i = 0; i < 4; i++)
    {
        if (white_pawn_moves[i] != 65)
        {
            moves++;
            // printf("white pawn %i ", white_pawn_moves[i]);
        }
        else if (black_pawn_moves[i] != 65)
        {
            moves++;
            // printf("black pawn %i ", black_pawn_moves[i]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (knight_moves[i] != 65)
        {
            moves++;
            // printf("%i ", knight_moves[i]);
        }
    }
    for (int i = 0; i < 13; i++)
    {
        if (bishop_moves[i] != 65)
        {
            moves++;
            // printf("%i ", bishop_moves[i]);
        }
    }
    for (int i = 0; i < 15; i++)
    {
        if (rook_moves[i] != 65)
        {
            moves++;
            // printf("%i ", rook_moves[i]);
        }
    }
    for (int i = 0; i < 27; i++)
    {
        if (queen_moves[i] != 65)
        {
            moves++;
            // printf("%i ", queen_moves[i]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (king_moves[i] != 65)
        {
            moves++;
            // printf("%i ", king_moves[i]);
        }
    }
    // printf("\n");

    total = moves + total;

    // printf("total moves are %i\n", moves);
}