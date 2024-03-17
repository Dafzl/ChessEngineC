#include <stdio.h>
#include <stdbool.h>

bool game_end(char *board)
{
    int pawns = 0, whiteknights = 0, blackknights = 0, whitebishops = 0, blackbishops = 0, rooks = 0, queens = 0;
    bool whiteking, blackking;

    // count every piece
    for (int i = 0; i < 64; i++)
    {
        // get piece
        char piece = board[i];

        // count every piece
        if (piece == 'p' || piece == 'P')
        {
            pawns++;
        }
        else if (piece == 'n')
        {
            whiteknights++;
        }
        else if (piece == 'N')
        {
            blackknights++;
        }
        else if (piece == 'b')
        {
            whitebishops++;
        }
        else if (piece == 'B')
        {
            blackbishops++;
        }
        else if (piece == 'r' || piece == 'R')
        {
            rooks++;
        }
        else if (piece == 'q' || piece == 'Q')
        {
            queens++;
        }
        else if (piece == 'k')
        {
            whiteking = true;
        }
        else if (piece == 'K')
        {
            blackking = true;
        }
    }

    // see who won
    if (whiteking == false)
    {
        printf("Black won!\n");
        return true;
    }
    if (blackking == false)
    {
        printf("White won!\n");
        return true;
    }

    // see if it's a draw
    if (blackking == true && whiteking == true)
    {
        // see if there is sufficient material except bishops and knights
        if (pawns == 0 && rooks == 0 && queens == 0)
        {
            // check for white bishops
            if (whitebishops > 1)
            {
                return false;
            }
            else if (whitebishops < 2)
            {
                // check for a white bishop
                if (whitebishops == 1)
                {
                    // check for a white knight
                    if (whiteknights != 0)
                    {
                        return false;
                    }
                }
                // check if there are sufficient knights for white
                else if (whiteknights > 2)
                {
                    return false;
                }
                // check for black bishops
                if (blackbishops > 1)
                {
                    return false;
                }
                else if (blackbishops < 2)
                {
                    // check for a black bishop
                    if (blackbishops == 1)
                    {
                        // check for a black knight
                        if (blackknights != 0)
                        {
                            return false;
                        }
                    }
                    // check for sufficient knights for black
                    if (blackknights > 2)
                    {
                        return false;
                    }
                    // else draw
                    else
                    {
                        printf("It's a draw!\n");
                        return true;
                    }
                }
            }
        }
        return false;
    }
    return false;
}