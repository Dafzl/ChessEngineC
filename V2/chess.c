#include <stdio.h>
// contains functions from other files
#include "functions.h"

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

int main(void)
{
    check(board);
    // do
    // {
    //     printboard(board);
    //     update_board();
    //     printboard(board);
    // } while (1);
}

void update_board()
{
    char *updates = user(board);
}