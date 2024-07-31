char *engine(char *board, int depth, int color);
void all_moves(char *board, int color);

// variables
int moves[75];
extern int white_pawn_moves[4];
extern int black_pawn_moves[4];
extern int knight_moves[8];
extern int bishop_moves[13];
extern int rook_moves[15];
extern int queen_moves[27];
extern int king_moves[8];

int total = 0;

char *engine(char *board, int depth, int color)
{
    if (depth < 0)
    {
        return board;
    }

    char *engine_board = board;

    if (color == 0)
    {
        all_moves(board, 0);
        for (int i = 0; i < 75; i++)
        {
            total++;
            engine_board[i] = '-';
            depth--;
            board = engine(board, depth, 1);
            engine_board = board;
        }
    }
    else if (color == 1)
    {
        all_moves(board, 1);
        for (int i = 0; i < 75; i++)
        {
            total++;
            engine_board[i] = '-';
            depth--;
            board = engine(board, depth, 0);
            engine_board = board;
        }
    }
    return board;
}

void all_moves(char *board, int color)
{
    // reset moves
    for (int i = 0; i < 75; i++)
    {
        moves[i] = 65;
    }

    // generate the moves
    char piece;
    for (int i = 0; i < 64; i++)
    {
        piece = board[i];
        if (color == 0)
        {
            if (96 < piece && piece < 123)
            {
                move_generation(board, i);
            }
        }
        else if (color == 1)
        {
            if (64 < piece && piece < 91)
            {
                move_generation(board, i);
            }
        }
    }

    // put all moves into moves
    int number_moves = 0;
    for (int pawn = 0; pawn < 4; pawn++)
    {
        if (color == 0)
        {
            moves[number_moves] = white_pawn_moves[pawn];
            number_moves++;
        }
        else if (color == 1)
        {
            moves[number_moves] = black_pawn_moves[pawn];
            number_moves++;
        }
    }
    for (int knight = 0; knight < 8; knight++)
    {
        moves[number_moves] = knight_moves[knight];
        number_moves++;
    }
    for (int bishop = 0; bishop < 13; bishop++)
    {
        moves[number_moves] = bishop_moves[bishop];
        number_moves++;
    }
    for (int rook = 0; rook < 15; rook++)
    {
        moves[number_moves] = rook_moves[rook];
        number_moves++;
    }
    for (int queen = 0; queen < 27; queen++)
    {
        moves[number_moves] = queen_moves[queen];
        number_moves++;
    }
    for (int king = 0; king < 8; king++)
    {
        moves[number_moves] = king_moves[king];
        number_moves++;
    }
}