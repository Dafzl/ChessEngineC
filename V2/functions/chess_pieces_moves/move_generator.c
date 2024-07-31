// decleration
void move_generation(char *board, int piece_coordinate);

// import the move_generators
#include "chess_pieces/pawn.c"
#include "chess_pieces/knight.c"
#include "chess_pieces/bishop.c"
#include "chess_pieces/rook.c"
#include "chess_pieces/queen.c"
#include "chess_pieces/king.c"
#include "move_filter.c"

// variables
char piece;

void move_generation(char *board, int piece_coordinate)
{
    // get the piece
    piece = board[piece_coordinate];

    // no piece
    if (piece == '-')
    {
        return;
    }
    // white
    else if (piece > 96 && piece < 123)
    {
        // pawn
        if (piece == 'p')
        {
            white_pawn_moves_generation(board, piece_coordinate);
            move_filter_pawn(0, board);
        }
        // knight
        if (piece == 'n')
        {
            knight_moves_generator(board, piece_coordinate);
            move_filter_knight(0, board);
        }
        // bishop
        else if (piece == 'b')
        {
            bishop_moves_generation(board, piece_coordinate);
            move_filter_bishop(0, board);
        }
        // rook
        else if (piece == 'r')
        {
            rook_moves_generation(board, piece_coordinate);
            move_filter_rook(0, board);
        }
        // queen
        else if (piece == 'q')
        {
            queen_moves_generation(board, piece_coordinate);
            move_filter_queen(0, board);
        }
        // king
        else if (piece == 'k')
        {
            queen_moves_generation(board, piece_coordinate);
            move_filter_queen(0, board);
        }
    }
    // black
    else if (piece > 64 && piece < 91)
    {
        // pawn
        if (piece == 'P')
        {
            black_pawn_moves_generation(board, piece_coordinate);
            move_filter_pawn(1, board);
        }
        // knight
        if (piece == 'N')
        {
            knight_moves_generator(board, piece_coordinate);
            move_filter_knight(1, board);
        }
        // bishop
        else if (piece == 'B')
        {
            bishop_moves_generation(board, piece_coordinate);
            move_filter_bishop(1, board);
        }
        // rook
        else if (piece == 'R')
        {
            rook_moves_generation(board, piece_coordinate);
            move_filter_rook(1, board);
        }
        // queen
        else if (piece == 'Q')
        {
            queen_moves_generation(board, piece_coordinate);
            move_filter_queen(1, board);
        }
        // king
        else if (piece == 'K')
        {
            king_moves_generation(board, piece_coordinate);
            move_filter_king(1, board);
        }
    }
}