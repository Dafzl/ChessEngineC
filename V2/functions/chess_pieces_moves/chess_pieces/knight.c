// decleration
void knight_moves_generator(char *board, int piece_coordinate);
void check_knight(char *board);


// variables
int knight_moves[8];
int move_number_knight;

void knight_moves_generator(char *board, int piece_coordinate)
{
    // reset move_number_knight and board
    move_number_knight = 0;
    for (int i = 0; i < 8; i++)
    {
        knight_moves[i] = 65;
    }

    // generate moves to the left
    if (piece_coordinate % 8 != 0)
    {
        // high top and bottom
        if (piece_coordinate < 48)
        {
            knight_moves[move_number_knight] = piece_coordinate + 15;
            move_number_knight++;
        }
        if (piece_coordinate > 15)
        {
            knight_moves[move_number_knight] = piece_coordinate - 17;
            move_number_knight++;
        }

        // low top and bottom
        if ((piece_coordinate - 1) % 8 != 0)
        {
            if (piece_coordinate < 56)
            {
                knight_moves[move_number_knight] = piece_coordinate + 6;
                move_number_knight++;
            }
            if (piece_coordinate > 7)
            {
                knight_moves[move_number_knight] = piece_coordinate - 10;
                move_number_knight++;
            }
        }
    }

    // generating moves to the right side
    if ((piece_coordinate + 1) % 8 != 0)
    {
        // high top and bottom
        if (piece_coordinate < 48)
        {
            knight_moves[move_number_knight] = piece_coordinate + 17;
            move_number_knight++;
        }
        if (piece_coordinate > 15)
        {
            knight_moves[move_number_knight] = piece_coordinate - 15;
            move_number_knight++;
        }

        // low top and bottom
        if ((piece_coordinate + 2) % 8 != 0)
        {
            if (piece_coordinate < 56)
            {
                knight_moves[move_number_knight] = piece_coordinate + 10;
                move_number_knight++;
            }
            if (piece_coordinate > 7)
            {
                knight_moves[move_number_knight] = piece_coordinate - 6;
                move_number_knight++;
            }
        }
    }
}

void check_knight(char *board)
{
    int moves = 0;
    for (int i = 0; i < 64; i++)
    {
        knight_moves_generator(board, i);
        for (int j = 0; j < 8; j++)
        {
            if (knight_moves[j] != 65)
            {
                moves++;
                // printf("%i ", knight_moves[j]);
            }
        }
    }

    printf("%i \n", moves);
}
