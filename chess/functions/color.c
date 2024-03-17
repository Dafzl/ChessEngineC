#include <stdio.h>
#include "whitemovegenerator.c"
#include "blackmovegenerator.c"

char *color(char *board, char piece, int place)
{
    // moves for white
    if (piece >= 97 && piece <= 122)
    {
        char *white = whitemove(board, piece, place);
        return white;
    }
    // moves for black
    else if (piece >= 65 && piece <= 90)
    {
        char *black = blackmove(board, piece, place);
        return black;
    }

    // return 0 if no move
    char *error = "BBB";
    return error;
}
