#include <stdio.h>
#include <cs50.h>

int selected(char *board, bool whitetomove)
{
    int letter, number, coordinate;
    bool possible;
    do
    {
        // get from user to select a piece
        string select = get_string("Select piece: ");

        // turn that string into the numbers
        letter = select[0] - 97;
        number = select[1] - 49;

        // print invalid piece if wrong
        if (letter > 7 || number > 7 || letter < 0 || number < 0)
        {
            printf("Invalid piece\n\n");
        }

        // see if the color is right
        coordinate = (number * 8) + letter;
        int piece = board[coordinate];

        if (piece == 45)
        {
            printf("Invalid piece\n\n");
            possible = false;
        }
        else if (whitetomove == true)
        {
            if (piece > 96 && piece < 123)
            {
                possible = true;
            }
            else
            {
                printf("Invalid piece\n\n");
                possible = false;
            }
        }
        else if (whitetomove == false)
        {
            if (piece > 64 && piece < 91)
            {
                possible = true;
            }
            else
            {
                printf("Invalid piece\n\n");
                possible = false;
            }
        }

    } while (letter > 7 || number > 7 || letter < 0 || number < 0 || possible == false);

    // turn those numbers into coordinates
    coordinate = (number * 8) + letter;

    return coordinate;
}

int usermove(char *board, bool whitetomove)
{
    int letter, number, coordinate;
    bool possible;
    do
    {
        // get from user to select a piece
        string select = get_string("Select move: ");
        // turn that string into the numbers
        letter = select[0] - 97;
        number = select[1] - 49;

        // print invalid piece if wrong
        if (letter > 7 || number > 7 || letter < 0 || number < 0)
        {
            printf("Invalid move\n\n");
        }

        // see if the move color is right
        coordinate = (number * 8) + letter;
        int piece = board[coordinate];

        if (piece == 45)
        {
            possible = true;
        }
        else if (whitetomove == false)
        {
            if (piece > 96 && piece < 123)
            {
                possible = true;
            }
            else
            {
                printf("Invalid move\n\n");
                possible = false;
            }
        }
        else if (whitetomove == true)
        {
            if (piece > 64 && piece < 91)
            {
                possible = true;
            }
            else
            {
                printf("Invalid move\n\n");
                possible = false;
            }
        }

    } while (letter > 7 || number > 7 || letter < 0 || number < 0 || possible == false);

    // turn those numbers into coordinates
    coordinate = (number * 8) + letter;

    return coordinate;
}

bool changetomove(bool whitetomove)
{
    bool change;
    if (whitetomove == true)
    {
        change = false;
    }
    else
    {
        change = true;
    }
    return change;
}