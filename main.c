#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "functions.c"

char board[64] = {
     'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'
    ,'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
    ,'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'
    ,'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
};
char testboard[64] = {
     '-', '-', '-', '-', '-', 'R', '-', '-'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
    ,'-', '-', '-', '-', '-', 'k', '-', '-'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
    ,'-', '-', '-', '-', '-', '-', '-', '-'
}; /*for testing*/
int user_color = 1;

int main()
{
    int finished;
    do
    {
        print_board(board);
        move_pieces(board);
        engine_move();
        finished = finish();
    } while (finished != 0);
    printf("Game has ended!\n");
}