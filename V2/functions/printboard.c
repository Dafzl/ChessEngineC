// decleration
void printboard(char *board);

// variables
int coordinate, row = 8;
char letter;

void printboard(char *board)
{
    coordinate;
    // print the rows-coordinates
    row = 8;
    printf("%i| ", row);

    // print the board
    for (int i = 7; i >= 0; i--)
    {
        for (int j = 0; j < 8; j++)
        {
            // calculate the coordinate
            coordinate = i * 8 + j;

            // print the piece in that coordinate
            printf("%c| ", board[coordinate]);
        }

        // print the coordinate letter
        printf("\n");
        if (row > 1)
        {
            row--;
            printf("%i| ", row);
        }
    }

    // print the column coordinates
    letter = 'A';
    printf("  ");
    for (int j = 0; j < 8; j++)
    {
        printf(" %c|", letter);
        letter++;
    }
    printf("\n");
}