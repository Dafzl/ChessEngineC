#include <stdio.h>
// contains functions from other files
// #include "debug.c"
#include "functions.h"
#include "engine.c"

void update_board();

// board
char board[64] = {'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r',
                  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
                  'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'};

char boardd[64] = {'-', '-', '-', '-', '-', '-', '-', '-',
                   '-', '-', '-', '-', '-', 'K', '-', '-',
                   '-', '-', '-', '-', '-', '-', '-', '-',
                   '-', '-', '-', '-', '-', '-', '-', '-',
                   '-', '-', '-', '-', '-', 'r', '-', '-',
                   '-', '-', '-', 'k', 'p', '-', 'R', '-',
                   '-', '-', '-', '-', '-', '-', '-', '-',
                   '-', '-', '-', '-', '-', '-', '-', '-'};

char empty[64] = {'-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-',
                  '-', '-', '-', '-', '-', '-', '-', '-'};

int main(void)
{
    int i = 0;
    extern int total;
    // debug(board);
    do
    {
        // printboard(board);
        // update_board();
        printboard(board);

        char *engine_board = engine(board, 20, 0);
        engine_board = board;
        i++;
        printf("the total moves thought ahead are %i\n", total);
    } while (i < 2);
}

void update_board()
{
    char *updates = user(board);
}