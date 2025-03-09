#include "pieces/pawn.c"
#include "pieces/knight.c"
#include "pieces/bishop.c"
#include "pieces/rook.c"
#include "pieces/king.c"

int possible_moves[28];

void reset_moves()
{
    for (int i = 0; i < 28; i++)
    {
        possible_moves[i] = 65;
    }
}

void move_gen(int square, char *board)
{
    int moves = 0;
    char piece = board[square];
    reset_moves();

    switch (tolower(piece))
    {
    case 'p':
        (islower(piece)) ? wpawn_mgen(square, &moves, board) : bpawn_mgen(square, &moves, board);
        break;
    case 'n':
        knight_mgen(square, &moves, board);
        break;
    case 'b':
        bishop_mgen(square, &moves, board);
        break;
    case 'r':
        rook_mgen(square, &moves, board);
        break;
    case 'q':
        bishop_mgen(square, &moves, board);
        rook_mgen(square, &moves, board);
        break;
    case 'k':
        king_mgen(square, &moves, board);
        break;
    default:
        break;
    }

    if (islower(piece))
    {
        for (int i = 0; i < 28; i++)
        {
            if (board[possible_moves[i]] != '-')
            {
                if (islower(board[possible_moves[i]]))
                {
                    possible_moves[i] = 65;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 28; i++)
        {
            if (board[possible_moves[i]] != '-')
            {
                if (isupper(board[possible_moves[i]]))
                {
                    possible_moves[i] = 65;
                }
            }
        }
    }
}