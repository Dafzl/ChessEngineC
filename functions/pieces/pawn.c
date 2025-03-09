#define nothing 65; /*to do nothing if the statement is false*/
extern int possible_moves[28];

int wpawn_mgen(int square, int *moves, char *board)
{
    if (board[square + 8] == '-')
    {
        possible_moves[*moves] = square + 8;
        (*moves)++;
        if ((board[square + 16] == '-') && square < 16)
        {
            possible_moves[*moves] = square + 16;
            (*moves)++;
        }
    }
    (((square + 1) % 8 != 0) && board[square + 9] != '-') ? ((possible_moves[*moves] = square + 9), (*moves)++) : nothing;
    ((square % 8 != 0) && board[square + 7] != '-') ? ((possible_moves[*moves] = square + 7), (*moves)++) : nothing;
    return 10; /*value of a pawn*/
}

int bpawn_mgen(int square, int *moves, char *board)
{
    if (board[square - 8] == '-')
    {
        possible_moves[*moves] = square - 8;
        (*moves)++;
        if ((board[square - 16] == '-') && square < 47)
        {
            possible_moves[*moves] = square - 16;
            (*moves)++;
        }
    }
    (((square + 1) % 8 != 0) && board[square - 7] != '-') ? ((possible_moves[*moves] = square - 7), (*moves)++) : nothing;
    ((square % 8 != 0) && board[square - 9] != '-') ? ((possible_moves[*moves] = square - 9), (*moves)++) : nothing;
    return 10; /*value of a pawn*/
}