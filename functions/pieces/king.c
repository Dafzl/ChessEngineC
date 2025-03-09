#define nothing 65;
extern int possible_moves[28];

int king_mgen(int square, int *moves, char *board)
{
    if (square % 8 != 0)
    {
        possible_moves[*moves] = square - 1;
        (*moves)++;
        (square > 7) ? (possible_moves[*moves] = square - 9) : nothing;
        (square < 56) ? (possible_moves[*moves] = square + 7) : nothing;
    }
    if ((square + 1) % 8 != 0)
    {
        possible_moves[*moves] = square + 1;
        (*moves)++;
        (square > 7) ? (possible_moves[*moves] = square - 7) : nothing;
        (square < 56) ? (possible_moves[*moves] = square + 9) : nothing;
    }
    return 999; /*value of a king*/
}