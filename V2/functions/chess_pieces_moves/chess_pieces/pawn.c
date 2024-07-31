// decleration
void white_pawn_moves_generation(char *board, int piece_coordinate);
void black_pawn_moves_generation(char *board, int piece_coordinate);
void check_white_pawn(char *board);
void check_black_pawn(char *board);

// variables
int white_pawn_moves[4], black_pawn_moves[4];
int move_number_pawn, generation_move;

void white_pawn_moves_generation(char *board, int piece_coordinate)
{
    // reset move_number_pawn, generation_move and white_pawn_moves
    move_number_pawn = 0;
    generation_move = 65;
    for (int i = 0; i < 4; i++)
    {
        white_pawn_moves[i] = 65;
    }
    // check if it's not on the last row
    if (55 < piece_coordinate)
    {
        return;
    }

    // generate moves top
    generation_move = piece_coordinate + 8;
    if (board[generation_move] == 45)
    {
        white_pawn_moves[move_number_pawn] = generation_move;
        move_number_pawn++;

        // check if it's the first move
        if (piece_coordinate > 7 && piece_coordinate < 16)
        {
            generation_move = piece_coordinate + 16;
            if (board[generation_move] == 45)
            {
                white_pawn_moves[move_number_pawn] = generation_move;
                move_number_pawn++;
            }
        }
    }
    // generate left capture
    generation_move = piece_coordinate + 7;
    // check if it's not on the first column
    if (piece_coordinate % 8 != 0)
    {
        if (board[generation_move] != 45)
        {
            white_pawn_moves[move_number_pawn] = generation_move;
            move_number_pawn++;
        }
    }
    // generate right capture
    generation_move = piece_coordinate + 9;
    // check if it's not on the last column
    if ((piece_coordinate + 1) % 8 != 0)
    {
        if (board[generation_move] != 45)
        {
            white_pawn_moves[move_number_pawn] = generation_move;
            move_number_pawn++;
        }
    }
}

void black_pawn_moves_generation(char *board, int piece_coordinate)
{
    // reset move_number_pawn, generation_move and black_pawn_moves
    move_number_pawn = 0;
    generation_move = 65;
    for (int i = 0; i < 4; i++)
    {
        black_pawn_moves[i] = 65;
    }
    // check if it's not on the first row
    if (piece_coordinate < 8)
    {
        return;
    }

    // generate moves top
    generation_move = piece_coordinate - 8;
    if (board[generation_move] == 45)
    {
        black_pawn_moves[move_number_pawn] = generation_move;
        move_number_pawn++;

        // check if it's the first move
        if (47 < piece_coordinate && piece_coordinate < 56)
        {
            generation_move = piece_coordinate - 16;
            if (board[generation_move] == 45)
            {
                black_pawn_moves[move_number_pawn] = generation_move;
                move_number_pawn++;
            }
        }
    }
    // generate left capture
    generation_move = piece_coordinate - 7;
    // check if it's not the last column
    if ((piece_coordinate + 1) % 8 != 0)
    {
        if (board[generation_move] != 45)
        {
            black_pawn_moves[move_number_pawn] = generation_move;
            move_number_pawn++;
        }
    }
    // generate right capture
    generation_move = piece_coordinate - 9;
    // check if it's not the first column
    if (piece_coordinate % 8 != 0)
    {
        if (board[generation_move] != 45)
        {
            black_pawn_moves[move_number_pawn] = generation_move;
            move_number_pawn++;
        }
    }
}

void check_white_pawn(char *board)
{
    int moves = 0;
    for (int i = 0; i < 64; i++)
    {
        white_pawn_moves_generation(board, i);
        for (int j = 0; j < 4; j++)
        {
            if (white_pawn_moves[j] != 65)
            {
                moves++;
                printf("%i ", white_pawn_moves[j]);
            }
        }
    }
    printf("\n");
    // printf("%i \n", moves);
}
void check_black_pawn(char *board)
{
    int moves = 0;
    for (int i = 0; i < 64; i++)
    {
        black_pawn_moves_generation(board, i);
        for (int j = 0; j < 4; j++)
        {
            if (black_pawn_moves[j] != 65)
            {
                moves++;
                printf("%i ", black_pawn_moves[j]);
            }
        }
    }
    printf("\n");
    // printf("%i \n", moves);
}