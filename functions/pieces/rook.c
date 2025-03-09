extern int possible_moves[28];

int rook_mgen(int square, int *moves, char *board)
{
    if (square % 8 != 0)
    {
        for (int left = 1; left <= (square % 8); left++)
        {
            possible_moves[*moves] = square - left;
            (*moves)++;
            if (board[possible_moves[*moves - 1]] != '-')
            {
                break;
            }
        }
    }
    if ((square + 1) % 8 != 0)
    {
        for (int right = 1; right <= (8 - (square + 1) % 8); right++)
        {
            possible_moves[*moves] = square + right;
            (*moves)++;
            if (board[possible_moves[*moves - 1]] != '-')
            {
                break;
            }
        }
    }
    if (square > 7)
    {
        for (int down = 1; down <= floor(square / 8); down++)
        {
            possible_moves[*moves] = square - (8 * down);
            (*moves)++;
            if (board[possible_moves[*moves - 1]] != '-')
            {
                break;
            }
        }
    }
    if (square < 56)
    {
        for (int up = 1; up <= floor((63 - square) / 8); up++)
        {
            possible_moves[*moves] = square + (8 * up);
            (*moves)++;
            if (board[possible_moves[*moves - 1]] != '-')
            {
                break;
            }
        }
    }
    return 50; /*value of a rook*/
}