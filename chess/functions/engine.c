#include <stdio.h>
#include <stdbool.h>
#include "output.c"

char engineboard[64] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
                        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
                        '-', '-', '-', '-', '-', '-', '-', '-',
                        '-', '-', '-', '-', '-', '-', '-', '-',
                        '-', '-', '-', '-', '-', '-', '-', '-',
                        '-', '-', '-', '-', '-', '-', '-', '-',
                        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
                        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};

char *engine(char *board, bool whitetomove)
{
    // make the engineboard the actual board
    for (int i = 0; i < 64; i++)
    {
        engineboard[i] = board[i];
    }

    if (whitetomove == true)
    {
        // generating every move for white
        for (int j = 0; j < 64; j++)
        {
            // looks which piece the loop is one
            char piece = engineboard[j];

            // looks if it's a white piece
            if (piece >= 97 && piece <= 122)
            {
                // generate moves
                char *move = moves(engineboard, piece, j);
                int length = strlen(move);

                // play the generated moves
                for (int k = 0; k < length; k++)
                {
                    int movecoordinate = move[k];
                    engineboard[movecoordinate] = piece;
                    engineboard[j] = '-';

                    // remake the position
                    engineboard[movecoordinate] = board[movecoordinate];
                    engineboard[j] = piece;
                }
            }
        }
    }
}