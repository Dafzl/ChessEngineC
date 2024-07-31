void king_moves_generation(char *board, int piece_coordinate);
void check_king(char *board);

// variables
int king_moves[8];
int move_number_king, generation_move;

void king_moves_generation(char *board, int piece_coordinate)
{
    // reset move_number_king, generation_move and king_moves
    move_number_king = 0;
    generation_move = 0;
    for (int i = 0; i < 8; i++)
    {
        king_moves[i] = 65;
    }

    // generate moves top
    generation_move = piece_coordinate + 8;
    if (piece_coordinate < 56)
    {
        king_moves[move_number_king] = generation_move;
        move_number_king++;
    }
    // generate moves bottom
    generation_move = piece_coordinate - 8;
    if (piece_coordinate > 7)
    {
        king_moves[move_number_king] = generation_move;
        move_number_king++;
    }
    // generate moves left
    generation_move = piece_coordinate - 1;
    if (piece_coordinate % 8 != 0)
    {
        king_moves[move_number_king] = generation_move;
        move_number_king++;
        // generate moves top left
        generation_move = piece_coordinate + 7;
        if (piece_coordinate < 56)
        {
            king_moves[move_number_king] = generation_move;
            move_number_king++;
        }
        // generate moves bottom left
        generation_move = piece_coordinate - 9;
        if (piece_coordinate > 7)
        {
            king_moves[move_number_king] = generation_move;
            move_number_king++;
        }
    }
    // generate moves right
    generation_move = piece_coordinate + 1;
    if ((piece_coordinate + 1) % 8 != 0)
    {
        king_moves[move_number_king] = generation_move;
        move_number_king++;
        // generate moves top right
        generation_move = piece_coordinate + 9;
        if (piece_coordinate < 56)
        {
            king_moves[move_number_king] = generation_move;
            move_number_king++;
        }
        // generate moves bottom right
        generation_move = piece_coordinate - 7;
        if (piece_coordinate > 7)
        {
            king_moves[move_number_king] = generation_move;
            move_number_king++;
        }
    }
}

void check_king(char *board)
{
    int moves = 0;
    for (int i = 0; i < 64; i++)
    {
        king_moves_generation(board, i);
        for (int j = 0; j < 8; j++)
        {
            if (king_moves[j] != 65)
            {
                moves++;
                printf("%i ", king_moves[j]);
            }
        }
    }
    printf("\n");
    printf("%i \n", moves);
}