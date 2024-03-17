#include <stdio.h>
#include "color.c"

char validmoves[27];

char *moves(char *board, char piece, int place)
{
    // gets all moves
    char *allmoves = color(board, piece, place);

    // getting the lenght of allmoves because used alot
    int length = strlen(allmoves);

    // clears the validmoves array
    for (int i = 0; i < 27; i++)
    {
        validmoves[i] = 0;
    }
    //  substracting the +1
    for (int j = 0; j < length; j++)
    {
        validmoves[j] = allmoves[j] - 1;
    }

    // only return moves that are on the board. 65 won't be returned
    for (int k = 0; k < 27; k++)
    {
        char current = validmoves[k];
        if (current == 65)
        {
            validmoves[k] = 0;
            return validmoves;
        }
    }

    // returning all moves
    return validmoves;
}