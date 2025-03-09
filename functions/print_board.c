int print_board(char *board)
{
    int square;
    for (int row = 8; row > 0; row--)
    {
        square = (row - 1) * 8;
        printf("%i |", row); // number coordinate
        for (int column = 0; column < 8; column++)
        {
            printf("%c ", board[square]);
            square++;
        }
        printf("\n");
    }

    // letter coordinates
    for (int i = 0; i < 20; i++)
    {
        printf("-");
    }
    printf("\n   ");
    for (int column = 0; column < 8; column++)
    {
        printf("%c ", 'A' + column);
    }
    printf("\n");
}