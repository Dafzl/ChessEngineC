#include <stdio.h>
#include <stdbool.h>

// looks for the next square and movecounter
int move, movecounter, nextmove;
// arrays for legal moves for each sort of piece
char legalmovesp[4], legalmovesn[8], legalmovesb[13], legalmovesr[14], legalmovesq[27], legalmovesk[8];
// array for error
char error[27];

char *whitemove(char *board, char piece, int place)
{
    // total move counter for array
    movecounter = 0;

    // generating moves for pawns
    if (piece == 'p')
    {
        // clear all legal moves before generating new ones
        for (int i = 0; i < 4; i++)
        {
            legalmovesp[i] = 66;
        }

        // generating moves

        // looks that the piece won't go off the board
        if (place + 8 >= 64)
        {
            return legalmovesp;
        }
        // move forward
        // looks for the piece on the next square
        nextmove = place + 8;
        move = board[nextmove];

        // looks if the square is free
        if (move == 45)
        {
            legalmovesp[movecounter] = nextmove + 1;
            movecounter++;

            // move two places if on beginning point
            if (place >= 8 && place <= 15)
            {
                // looks for the piece on the next square
                nextmove = place + 16;
                move = board[nextmove];

                // looks if the square is free
                if (move == 45)
                {
                    legalmovesp[movecounter] = nextmove + 1;
                    movecounter++;
                }
            }
        }

        // capture pieces
        // check that the pieces won't jump to the other side
        bool captureleft = true;
        bool captureright = true;

        // change the boolean expressions if piece is on the edge
        if (place % 8 == 0)
        {
            captureleft = false;
        }
        if ((place + 1) % 8 == 0)
        {
            captureright = false;
        }

        // generate right capture move
        if (captureleft == true)
        {
            // looks for the piece on the next square
            nextmove = place + 7;
            move = board[nextmove];

            // looks if it's a black piece
            if (move >= 65 && move <= 90)
            {
                legalmovesp[movecounter] = nextmove + 1;
                movecounter++;
            }
            // look it's an en passent
            else if (move == 36)
            {
                legalmovesp[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // generate left capture move
        if (captureright == true)
        {
            // looks for the piece on the next square
            nextmove = place + 9;
            move = board[nextmove];

            // looks if it's a black piece
            if (move >= 65 && move <= 90)
            {
                legalmovesp[movecounter] = nextmove + 1;
                movecounter++;
            }
            // look it's an en passent
            else if (move == 36)
            {
                legalmovesp[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // fix random error of return next move
        nextmove = 66;
        // return the legal moves for pawn
        return legalmovesp;
    }

    // generating moves for knights
    if (piece == 'n')
    {
        // clear all legal moves before generating new ones
        for (int i = 0; i < 8; i++)
        {
            legalmovesn[i] = 66;
        }

        // generating moves
        // moves are chronologically written meaning if first top then right, go first 2 squares up then to right.

        // looks if the piece is not on the edges so that it doesn't jump to the other side

        // looks if the place is not on the left edge
        if (place % 8 != 0)
        {
            // looks that the piece won't jump off the board with +
            if (place < 48)
            {
                // generating move for top left
                nextmove = place + 15;
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesn[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesn[movecounter] = nextmove + 1;
                    movecounter++;
                }
            }

            // looks that the piece won't jump off the board with -
            if (place > 15)
            {
                // generating move for bottom left
                nextmove = place - 17;
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesn[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesn[movecounter] = nextmove + 1;
                    movecounter++;
                }
            }

            // looks if the place is not one square away from the left edge
            if ((place - 1) % 8 != 0)
            {
                // looks that the piece won't jump off the board with +
                if (place < 56)
                {
                    // generating move for left top
                    nextmove = place + 6;
                    move = board[nextmove];

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesn[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesn[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                }

                // looks that the piece won't jump off the board with -
                if (place > 8)
                {
                    // generating move for left bottom
                    nextmove = place - 10;
                    move = board[nextmove];

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesn[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesn[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                }
            }
        }

        // looks if the place is not on the right edge
        if ((place + 1) % 8 != 0)
        {
            // looks that hte piece won't jump off the board with +
            if (place < 48)
            {
                // generating move for top right
                nextmove = place + 17;
                move = board[nextmove];

                // looks if the square is valid/free to move
                if (move == 45)
                {
                    legalmovesn[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesn[movecounter] = nextmove + 1;
                    movecounter++;
                }
            }

            // looks that the piece won't jump off the board with -
            if (place > 15)
            {
                // generating move for bottom right
                nextmove = place - 15;
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesn[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesn[movecounter] = nextmove + 1;
                    movecounter++;
                }
            }

            // looks if the place is not one square away from the right edge
            if ((place + 2) % 8 != 0)
            {
                // looks that the piece won't jump off the board with +
                if (place < 56)
                {
                    // generating move for right top
                    nextmove = place + 10;
                    move = board[nextmove];

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesn[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesn[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                }

                // looks if that the piece won't jump off the board with -
                if (place > 8)
                {
                    // generating move for right bottom
                    nextmove = place - 6;
                    move = board[nextmove];

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesn[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    if (move >= 65 && move <= 90)
                    {
                        legalmovesn[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                }
            }
        }

        // return the legal moves for knight
        return legalmovesn;
    }

    // generating moves for bishop
    if (piece == 'b')
    {
        // clear all legal moves before generating new ones
        for (int i = 0; i < 13; i++)
        {
            legalmovesb[i] = 66;
        }

        // generating moves

        // looks if the piece is not on the left edge to generate moves to the left
        if (place % 8 != 0)
        {
            // boolean expression so that the piece doesn't jump another piece or to the other side of the board
            bool top = false, down = false;
            // generating moves for top left and down left
            for (int j = 0; j < 7; j++)
            {
                // generating moves for top left
                nextmove = place + 7 + (7 * j);

                // looks that the piece doesn't jump off the board with +
                if (nextmove > 63)
                {
                    top = true;
                }
                // generating the moves
                if (top == false)
                {
                    // looks for the piece on the next square
                    move = board[nextmove];
                    // looks that the piece doesn't jump to the other side of the board
                    if (nextmove % 8 == 0)
                    {
                        top = true;
                    }

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesb[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesb[movecounter] = nextmove + 1;
                        movecounter++;
                        top = true;
                    }
                    // looks that the move isn't a white piece
                    else if (move >= 97 && move <= 122)
                    {
                        top = true;
                    }
                }

                // generating moves for down left
                nextmove = place - 9 - (9 * j);

                // looks that the piece doesn't jump off the board with -
                if (nextmove < 0)
                {
                    down = true;
                }
                // generating the moves
                if (down == false)
                {
                    // looks for the piece on the next square
                    move = board[nextmove];
                    // looks that the piece doesn't jump to the other side of the board
                    if (nextmove % 8 == 0)
                    {
                        down = true;
                    }

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesb[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesb[movecounter] = nextmove + 1;
                        movecounter++;
                        down = true;
                    }
                    // looks that the move isn't a white piece
                    else if (move >= 97 && move <= 122)
                    {
                        down = true;
                    }
                }
            }
        }

        // looks if the piece isn't on the right edge to generate moves to the right
        if ((place + 1) % 8 != 0)
        {
            // boolean expression so that the piece doesn't jump another piece or to the other side of the board
            bool top = false, down = false;
            // generating moves for top right and down right
            for (int k = 0; k < 7; k++)
            {
                // generating moves for top right
                nextmove = place + 9 + (9 * k);

                // looks that the piece doesn't jump off the board with +
                if (nextmove > 63)
                {
                    top = true;
                }
                // generating the moves
                if (top == false)
                {
                    // looks for the piece on the next square
                    move = board[nextmove];
                    // looks that the piece doesn't jump to the other side of the board
                    if ((nextmove + 1) % 8 == 0)
                    {
                        top = true;
                    }

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesb[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesb[movecounter] = nextmove + 1;
                        movecounter++;
                        top = true;
                    }
                    // looks that the move isn't a white piece
                    else if (move >= 97 && move <= 122)
                    {
                        top = true;
                    }
                }

                // generating moves for down right
                nextmove = place - 7 - (7 * k);

                // looks that the piece doesn't jump off the board with -
                if (nextmove < 0)
                {
                    down = true;
                }
                // generating the moves
                if (down == false)
                {
                    // looks for the piece on the next square
                    move = board[nextmove];
                    // looks that the piece doesn't jump to the other side of the board
                    if ((nextmove + 1) % 8 == 0)
                    {
                        down = true;
                    }

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesb[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesb[movecounter] = nextmove + 1;
                        movecounter++;
                        down = true;
                    }
                    // looks that the move isn't a white piece
                    else if (move >= 97 && move <= 122)
                    {
                        down = true;
                    }
                }
            }
        }

        // return the legal moves for bishop
        return legalmovesb;
    }

    // generating moves for rook
    if (piece == 'r')
    {
        bool top = false, down = false, right = false, left = false;
        // clear all legal moves before generating new ones
        for (int i = 0; i < 14; i++)
        {
            legalmovesr[i] = 66;
        }

        // generating moves
        for (int i = 0; i < 14; i++)
        {
            // generating move for left
            nextmove = place - 1 - (1 * i);
            // looks that the piece doesn't jump to the other side of the board
            if ((nextmove + 1) % 8 == 0)
            {
                left = true;
            }
            // generating the moves
            if (left == false)
            {
                // looks for the piece on the next square
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesr[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesr[movecounter] = nextmove + 1;
                    movecounter++;
                    left = true;
                }
                // looks that the move isn't a white piece
                else if (move >= 97 && move <= 122)
                {
                    left = true;
                }
            }

            // generating move for right
            nextmove = place + 1 + (1 * i);
            // looks that the piece doesn't jump to the other side of the board
            if (nextmove % 8 == 0)
            {
                right = true;
            }
            // generating the moves
            if (right == false)
            {
                // looks for the piece on the next square
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesr[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesr[movecounter] = nextmove + 1;
                    movecounter++;
                    right = true;
                }
                // looks that the move isn't a white piece
                else if (move >= 97 && move <= 122)
                {
                    right = true;
                }
            }

            // generating move for top
            nextmove = place + 8 + (8 * i);
            // looks that the piece doesn't jump from the board
            if (nextmove > 63)
            {
                top = true;
            }
            // generating the moves
            if (top == false)
            {
                // looks for the piece on the next square
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesr[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesr[movecounter] = nextmove + 1;
                    movecounter++;
                    top = true;
                }
                // looks that the move isn't a white piece
                else if (move >= 97 && move <= 122)
                {
                    top = true;
                }
            }

            // generating move for down
            nextmove = place - 8 - (8 * i);
            // looks that the piece doesn't jump from the board
            if (nextmove < 0)
            {
                down = true;
            }
            // generating the moves
            if (down == false)
            {
                // looks for the piece on the next square
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesr[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesr[movecounter] = nextmove + 1;
                    movecounter++;
                    down = true;
                }
                // looks that the move isn't a white piece
                else if (move >= 97 && move <= 122)
                {
                    down = true;
                }
            }
        }

        // return the legal moves for rook
        return legalmovesr;
    }

    // generating moves for queen
    if (piece == 'q')
    {
        // clear all legal moves before generating new ones
        for (int i = 0; i < 27; i++)
        {
            legalmovesq[i] = 66;
        }

        // generating moves

        // bishop-like moves
        // looks if the piece is not on the left edg eto generate moves to the left
        if (place % 8 != 0)
        {
            // boolean expression so that the piece doesn't jump another piece or to the other side of the board
            // d for diagonal
            bool topd = false, downd = false;
            // generating moves for top left and down left
            for (int j = 0; j < 7; j++)
            {
                // generating moves for top left
                nextmove = place + 7 + (7 * j);

                // looks that the piece doesn't jump off the board with +
                if (nextmove > 63)
                {
                    topd = true;
                }
                // generating the moves
                if (topd == false)
                {
                    // looks for the piece on the next square
                    move = board[nextmove];
                    // looks that the piece doesn't jump to the other side of the board
                    if (nextmove % 8 == 0)
                    {
                        topd = true;
                    }

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesq[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesq[movecounter] = nextmove + 1;
                        movecounter++;
                        topd = true;
                    }
                    // looks that the move isn't a white piece
                    else if (move >= 97 && move <= 122)
                    {
                        topd = true;
                    }
                }

                // generating moves for down left
                nextmove = place - 9 - (9 * j);

                // looks that the piece doesn't jump off the board with -
                if (nextmove < 0)
                {
                    downd = true;
                }
                // generating the moves
                if (downd == false)
                {
                    // looks for the piece on the next square
                    move = board[nextmove];
                    // looks that the piece doesn't jump to the other side of the board
                    if (nextmove % 8 == 0)
                    {
                        downd = true;
                    }

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesq[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesq[movecounter] = nextmove + 1;
                        movecounter++;
                        downd = true;
                    }
                    // looks that the move isn't a white piece
                    else if (move >= 97 && move <= 122)
                    {
                        downd = true;
                    }
                }
            }
        }

        // looks if the piece isn't on the right edge to generate moves to the right
        if ((place + 1) % 8 != 0)
        {
            // boolean expression so that the piece doesn't jump another piece or to the other side of the board
            // d for diagonal
            bool topd = false, downd = false;
            // generating moves for top right and down right
            for (int k = 0; k < 7; k++)
            {
                // generating moves for top right
                nextmove = place + 9 + (9 * k);

                // looks that the piece doesn't jump off the board with +
                if (nextmove > 63)
                {
                    topd = true;
                }
                // generating the moves
                if (topd == false)
                {
                    // looks for the piece on the next square
                    move = board[nextmove];
                    // looks that the piece doesn't jump to the other side of the board
                    if ((nextmove + 1) % 8 == 0)
                    {
                        topd = true;
                    }

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesq[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesq[movecounter] = nextmove + 1;
                        movecounter++;
                        topd = true;
                    }
                    // looks that the move isn't a white piece
                    else if (move >= 97 && move <= 122)
                    {
                        topd = true;
                    }
                }

                // generating moves for down right
                nextmove = place - 7 - (7 * k);

                // looks that the piece doesn't jump off the board with -
                if (nextmove < 0)
                {
                    downd = true;
                }
                // generating the moves
                if (downd == false)
                {
                    // looks for the piece on the next square
                    move = board[nextmove];
                    // looks that the piece doesn't jump to the other side of the board
                    if ((nextmove + 1) % 8 == 0)
                    {
                        downd = true;
                    }

                    // looks if the square is valid/free to move to
                    if (move == 45)
                    {
                        legalmovesq[movecounter] = nextmove + 1;
                        movecounter++;
                    }
                    else if (move >= 65 && move <= 90)
                    {
                        legalmovesq[movecounter] = nextmove + 1;
                        movecounter++;
                        downd = true;
                    }
                    // looks that the move isn't a white piece
                    else if (move >= 97 && move <= 122)
                    {
                        downd = true;
                    }
                }
            }
        }

        // generating rook-like moves
        // declare variables
        bool top = false, down = false, right = false, left = false;

        // generating the moves
        for (int l = 0; l < 14; l++)
        {
            // generating move for left
            nextmove = place - 1 - (1 * l);
            // looks that the piece doesn't jump to the other side of the board
            if ((nextmove + 1) % 8 == 0)
            {
                left = true;
            }
            // generating the moves
            if (left == false)
            {
                // looks for the piece on the next square
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesq[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesq[movecounter] = nextmove + 1;
                    movecounter++;
                    left = true;
                }
                // looks that the move isn't a white piece
                else if (move >= 97 && move <= 122)
                {
                    left = true;
                }
            }

            // generating move for right
            nextmove = place + 1 + (1 * l);
            // looks that the piece doesn't jump to the other side of the board
            if (nextmove % 8 == 0)
            {
                right = true;
            }
            // generating the moves
            if (right == false)
            {
                // looks for the piece on the next square
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesq[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesq[movecounter] = nextmove + 1;
                    movecounter++;
                    right = true;
                }
                // looks that the move isn't a white piece
                else if (move >= 97 && move <= 122)
                {
                    right = true;
                }
            }

            // generating move for top
            nextmove = place + 8 + (8 * l);
            // looks that the piece doesn't jump from the board
            if (nextmove > 63)
            {
                top = true;
            }
            // generating the moves
            if (top == false)
            {
                // looks for the piece on the next square
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesq[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesq[movecounter] = nextmove + 1;
                    movecounter++;
                    top = true;
                }
                // looks that the move isn't a white piece
                else if (move >= 97 && move <= 122)
                {
                    top = true;
                }
            }

            // generating move for down
            nextmove = place - 8 - (8 * l);
            // looks that the piece doesn't jump from the board
            if (nextmove < 0)
            {
                down = true;
            }
            // generating the moves
            if (down == false)
            {
                // looks for the piece on the next square
                move = board[nextmove];

                // looks if the square is valid/free to move to
                if (move == 45)
                {
                    legalmovesq[movecounter] = nextmove + 1;
                    movecounter++;
                }
                else if (move >= 65 && move <= 90)
                {
                    legalmovesq[movecounter] = nextmove + 1;
                    movecounter++;
                    down = true;
                }
                // looks that the move isn't a white piece
                else if (move >= 97 && move <= 122)
                {
                    down = true;
                }
            }
        }

        // return the legal moves for queen
        return legalmovesq;
    }

    // generating moves for king
    if (piece == 'k')
    {
        // clear all legal moves before generating new ones
        for (int i = 0; i < 8; i++)
        {
            legalmovesk[i] = 66;
        }

        // generating moves

        // move up
        // looks for the piece on the next square
        nextmove = place + 8;
        // generating move
        if (nextmove < 64)
        {
            move = board[nextmove];

            // looks if the square is free or valid to move to
            if (move == 45)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
            else if (move >= 65 && move <= 90)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // move up right
        // looks for the piece on the next square
        nextmove = place + 9;
        // generating move
        if (nextmove < 64 && (place + 1) % 8 != 0)
        {
            move = board[nextmove];

            // looks if the square is free or valid to move to
            if (move == 45)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
            else if (move >= 65 && move <= 90)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // move up left
        // looks for the piece on the next square
        nextmove = place + 7;
        // generating move
        if (nextmove < 64 && place % 8 != 0)
        {
            move = board[nextmove];

            // looks if the square is free or valid to move to
            if (move == 45)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
            else if (move >= 65 && move <= 90)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // move down
        // looks for the piece on the next square
        nextmove = place - 8;
        // generating move
        if (nextmove >= 0)
        {
            move = board[nextmove];

            // looks if the square is free or valid to move to
            if (move == 45)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
            else if (move >= 65 && move <= 90)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // move down right
        // looks for the piece on the next square
        nextmove = place - 7;
        // generating move
        if (nextmove >= 0 && (place + 1) % 8 != 0)
        {
            move = board[nextmove];

            // looks if the square is free or valid to move to
            if (move == 45)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
            else if (move >= 65 && move <= 90)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // move down left
        // looks for the piece on the next square
        nextmove = place - 9;
        // generating move
        if (nextmove >= 0 && place % 8 != 0)
        {
            move = board[nextmove];

            // looks if the square is free or valid to move to
            if (move == 45)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
            else if (move >= 65 && move <= 90)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // move left
        // looks for the piece on the next square
        nextmove = place - 1;
        // generating move
        if (place % 8 != 0)
        {
            move = board[nextmove];

            // looks if the square is free or valid to move to
            if (move == 45)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
            else if (move >= 65 && move <= 90)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // move right
        // looks for the piece on the next square
        nextmove = place + 1;
        // generating move
        if ((place + 1) % 8 != 0)
        {
            move = board[nextmove];

            // looks if the square is free or valid to move to
            if (move == 45)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
            else if (move >= 65 && move <= 90)
            {
                legalmovesk[movecounter] = nextmove + 1;
                movecounter++;
            }
        }

        // return the legal moves of king
        return legalmovesk;
    }

    // return error if no move
    char *error = "BB";
    return error;
}