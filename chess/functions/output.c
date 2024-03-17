#include <stdio.h>
#include <stdbool.h>
#include "userinput.c"
#include "moves.c"

char *output(char *board, bool whitetomove)
{
    // variables
    int selectcoordinate, selectmove, length;
    char piece;

    // user input
    selectcoordinate = selected(board, whitetomove);
    selectmove = usermove(board, whitetomove);

    // looking if the move is valid according to the generated moves

    // generating for white
    if (whitetomove == true)
    {
        piece = board[selectcoordinate];
        char *move = moves(board, piece, selectcoordinate);
        length = strlen(move);

        for (int i = 0; i < length; i++)
        {
            char movechecker = move[i];
            if (movechecker == selectmove)
            {
                // move piece
                board[selectmove] = board[selectcoordinate];
                board[selectcoordinate] = '-';

                // return board
                return board;
            }
        }
    }

    // generating for black
    else
    {
        piece = board[selectcoordinate];
        char *move = moves(board, piece, selectcoordinate);
        length = strlen(move);

        for (int i = 0; i < length; i++)
        {
            char movechecker = move[i];
            if (movechecker == selectmove)
            {
                // move piece
                board[selectmove] = board[selectcoordinate];
                board[selectcoordinate] = '-';

                // return board
                return board;
            }
        }
    }

    // if false move: return board and say invalid move
    printf("\nInvalid move\n");
    output(board, whitetomove);
    return board;
}
