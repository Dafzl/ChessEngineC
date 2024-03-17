#include <string.h>
#include <stdio.h>
// chess.c contains all functions together and is just simplification, functions.h has all functions
#include "functions.h"

// global variables
bool whitetomove = true, end = false;

// board
char boardd[64] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
                  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
                  'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};

char board[64] = {'-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', 'K', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', 'r', '-', '-',
                  '-', '-', '-', 'k', 'p', '-', 'R', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',};

int main(void)
{

    // play game
    do
    {
        // print board
        printboard(board);

        // check if move is working
        // char *move = moves(board, board[63], 63);
        // for (int i = 0; i < strlen(move); i++)
        // {
        //     printf("%i", move[i]);
        //     printf(" ");
        // }
        // printf("\n");

        // check
        int amountofmoves = 0;
        for (int i = 0; i < 64; i++)
        {
            char *move = moves(board, board[i], i);
            for (int j = 0; j < strlen(move); j++)
            {
                printf("%i", move[j]);
                printf(" ");
                amountofmoves++;
            }
        }
        printf("\n%d \n", amountofmoves);

        // change the board to the new position of the move
        char *new = output(board, whitetomove);
        for (int j = 0; j < 64; j++)
        {
            board[j] = new[j];
        }
        // change the color after a move
        whitetomove = changetomove(whitetomove);

        // check if the game has ended
        end = game_end(board);
    } while (end == false);
}