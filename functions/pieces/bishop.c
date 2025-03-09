extern int possible_moves[28];

int bishop_mgen(int square, int *moves, char *board)
{
    int max = 0;
    if ((square % 8 != 0) && (square < 56)) /*top left*/
    {
        max = ((square % 8) < (floor((63 - square) / 8))) ? square % 8 : floor((63 - square) / 8); /*calculate the maximum amount of moves in the direction*/
        for (int tl = 1; tl <= max; tl++)
        {
            possible_moves[*moves] = square + tl * 7;
            (*moves)++;
            if (board[possible_moves[*moves - 1]] != '-')
            {
                break;
            }
        }
    }
    if (((square + 1) % 8 != 0) && (square < 56)) /*top right*/
    {
        max = ((8 - (square + 1) % 8) < (floor((63 - square) / 8))) ? (8 - (square + 1) % 8) : (floor((63 - square) / 8));
        for (int tr = 1; tr <= max; tr++)
        {
            possible_moves[*moves] = square + tr * 9;
            (*moves)++;
            if (board[possible_moves[*moves - 1]] != '-')
            {
                break;
            }
        }
    }
    if ((square % 8 != 0) && (square > 7)) /*dow left*/
    {
        max = ((square % 8) < floor(square / 8)) ? square % 8 : floor(square / 8);
        for (int dl = 1; dl <= max; dl++)
        {
            possible_moves[*moves] = square - dl * 9;
            (*moves)++;
            if (board[possible_moves[*moves - 1]] != '-')
            {
                break;
            }
        }
    }
    if (((square + 1) % 8 != 0) && (square > 7)) /*down right*/
    {
        max = ((8 - (square + 1) % 8) < floor(square / 8)) ? (8 - (square + 1) % 8) : floor(square / 8);
        for (int dr = 1; dr <= max; dr++)
        {
            possible_moves[*moves] = square - dr * 7;
            (*moves)++;
            if (board[possible_moves[*moves - 1]] != '-')
            {
                break;
            }
        }
    }
    return 33; /*value of a bishop*/
}