extern char board[64];

int finish()
{
    int white_king = 0, black_king = 0;
    for (int i = 0; i < 64; i++)
    {
        if (board[i] == 'k')
        {
            white_king = 1;
        }
        else if (board[i] == 'K')
        {
            black_king = 1;
        }
    }
    int a = (white_king == 1 && black_king == 1) ? 1 : 0;
    printf("%i\n", a);
    return a;
}