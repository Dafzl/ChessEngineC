// decleration
void move_filter_pawn(int color, char *board);
void move_filter_knight(int color, char *board);
void move_filter_bishop(int color, char *board);
void move_filter_rook(int color, char *board);
void move_filter_queen(int color, char *board);
void move_filter_king(int color, char *board);
void reset_moves();

// variables
extern int white_pawn_moves[4];
extern int black_pawn_moves[4];
extern int knight_moves[8];
extern int bishop_moves[13];
extern int rook_moves[15];
extern int queen_moves[27];
extern int king_moves[8];
int filter;

// remove moves that capture their own pieces with 0 == white and 1 == black
void move_filter_pawn(int color, char *board)
{
    if (color == 0)
    {
        for (filter = 0; filter < 4; filter++)
        {
            if (board[white_pawn_moves[filter]] > 96 && board[white_pawn_moves[filter]] < 123)
            {
                white_pawn_moves[filter] = 65;
            }
        }
    }
    else if (color == 1)
    {
        for (filter = 0; filter < 4; filter++)
        {
            if (board[black_pawn_moves[filter]] > 64 && board[black_pawn_moves[filter]] < 91)
            {
                black_pawn_moves[filter] = 65;
            }
        }
    }
}
void move_filter_knight(int color, char *board)
{
    if (color == 0)
    {
        for (filter = 0; filter < 8; filter++)
        {
            if (board[knight_moves[filter]] > 96 && board[knight_moves[filter]] < 123)
            {
                knight_moves[filter] = 65;
            }
        }
    }
    else if (color == 1)
    {
        for (filter = 0; filter < 8; filter++)
        {
            if (board[knight_moves[filter]] > 64 && board[knight_moves[filter]] < 91)
            {
                knight_moves[filter] = 65;
            }
        }
    }
}
void move_filter_bishop(int color, char *board)
{
    if (color == 0)
    {
        for (filter = 0; filter < 13; filter++)
        {
            if (board[bishop_moves[filter]] > 96 && board[bishop_moves[filter]] < 123)
            {
                bishop_moves[filter] = 65;
            }
        }
    }
    else if (color == 1)
    {
        for (filter = 0; filter < 13; filter++)
        {
            if (board[bishop_moves[filter]] > 64 && board[bishop_moves[filter]] < 91)
            {
                bishop_moves[filter] = 65;
            }
        }
    }
}
void move_filter_rook(int color, char *board)
{
    if (color == 0)
    {
        for (filter = 0; filter < 15; filter++)
        {
            if (board[rook_moves[filter]] > 96 && board[rook_moves[filter]] < 123)
            {
                rook_moves[filter] = 65;
            }
        }
    }
    else if (color == 1)
    {
        for (filter = 0; filter < 15; filter++)
        {
            if (board[rook_moves[filter]] > 64 && board[rook_moves[filter] < 91])
            {
                rook_moves[filter] = 65;
            }
        }
    }
}
void move_filter_queen(int color, char *board)
{
    if (color == 0)
    {
        for (filter = 0; filter < 27; filter++)
        {
            if (board[queen_moves[filter]] > 96 && board[queen_moves[filter]] < 123)
            {
                queen_moves[filter] = 65;
            }
        }
    }
    else if (color == 1)
    {
        for (filter = 0; filter < 27; filter++)
        {
            if (board[queen_moves[filter]] > 64 && board[queen_moves[filter]] < 91)
            {
                queen_moves[filter] = 65;
            }
        }
    }
}
void move_filter_king(int color, char *board)
{
    if (color == 0)
    {
        for (filter = 0; filter < 8; filter++)
        {
            if (board[king_moves[filter]] > 96 && board[king_moves[filter]] < 123)
            {
                king_moves[filter] = 65;
            }
        }
    }
    else if (color == 1)
    {
        for (filter = 0; filter < 8; filter++)
        {
            if (board[king_moves[filter]] > 64 && board[king_moves[filter]] < 91)
            {
                king_moves[filter] = 65;
            }
        }
    }
}

void reset_moves()
{
    int i;

    // white pawn
    for (i = 0; i < 4; i++)
    {
        white_pawn_moves[i] = 65;
    }
    // black pawn
    for (i = 0; i < 4; i++)
    {
        black_pawn_moves[i] = 65;
    }
    // knight
    for (i = 0; i < 8; i++)
    {
        knight_moves[i] = 65;
    }
    // bishop
    for (i = 0; i < 13; i++)
    {
        bishop_moves[i] = 65;
    }
    // rook
    for (i = 0; i < 15; i++)
    {
        rook_moves[i] = 65;
    }
    // queen
    for (i = 0; i < 27; i++)
    {
        queen_moves[i] = 65;
    }
    // king
    for (i = 0; i < 8; i++)
    {
        king_moves[i] = 65;
    }
}