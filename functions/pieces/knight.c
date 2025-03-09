#define nothing 65; /*to do nothing if the statement is false*/
extern int possible_moves[28];

int knight_mgen(int square, int *moves, char *board)
{
    if (square < 56)
    {
        (square % 8 >= 2) ? (possible_moves[*moves] = square + 6, (*moves)++) : nothing; /*short top left*/
        (square % 8 < 6) ? (possible_moves[*moves] = square + 10, (*moves)++) : nothing; /*short top right*/
        if (square < 48)
        {
            (square % 8 >= 1) ? (possible_moves[*moves] = square + 15, (*moves)++) : nothing; /*long top left*/
            (square % 8 < 7) ? (possible_moves[*moves] = square + 17, (*moves)++) : nothing;  /*long top right*/
        }
    }
    if (square > 7)
    {
        (square % 8 >= 2) ? (possible_moves[*moves] = square - 10, (*moves)++) : nothing; /*short bottom left*/
        (square % 8 < 6) ? (possible_moves[*moves] = square - 6, (*moves)++) : nothing;   /*short bottom right*/
        if (square > 15)
        {
            (square % 8 >= 1) ? (possible_moves[*moves] = square - 17, (*moves)++) : nothing; /*long bottom left*/
            (square % 8 < 7) ? (possible_moves[*moves] = square - 15, (*moves)++) : nothing;  /*long bottom right*/
        }
    }
    return 31; /*value of a knight*/
}