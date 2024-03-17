#include <stdio.h>

void printboard(char *board)
{
    int j = 7;
    for (int i = 8; i > 0; i--)
    {
        // print coordinate numbers
        printf("%i|", i);

        // print board
        for (int k = 0; k < 8; k++)
        {
            printf(" %c ", board[k + (8 * j)]);
        }
        printf("\n");
        j--;
    }

    // print line to seperate board from coordinate letters
    for (int l = 0; l < 26; l++)
    {
        printf("-");
    }
    printf("\n ");

    // print coordinate letters
    for (int m = 0; m < 8; m++)
    {
        printf("  %c", m + 65);
    }

    printf("\n\n");
}