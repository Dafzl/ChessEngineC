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

// int main()
// {
//     int square = 8;
//     // board[square] = 'q';
//     move_gen(square);
//     for (int i = 0; i < 28; i++)
//     {
//         printf("%i ", possible_moves[i]);
//     }
//     printf("\n");
// }



int main()
{
    do
    {
        print_board(board);
        move_pieces(board);
        print_board(board);
        engine(board);

        // fix not always legal move generation
        board[top_move] = board[piecetomove];
        board[piecetomove] = '-';
    } while (true);
    
    // print_board(board);
    // engine(board);
    // // move_pieces(board);
    // print_board(board);
}
