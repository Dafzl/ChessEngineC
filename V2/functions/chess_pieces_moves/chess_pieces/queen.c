// decleration
void queen_moves_generation(char *board, int piece_coordinate);
void check_queen(char *board);

// variables
int queen_moves[27];
int move_number_queen, generation_move;

void queen_moves_generation(char *board, int piece_coordinate)
{
    // reset queen_moves, move_number_queen and generation_move
    move_number_queen = 0;
    generation_move = 65;
    for (int i = 0; i < 27; i++)
    {
        queen_moves[i] = 65;
    }

    // generate moves top left
    for (int top_left = 1; top_left < 8; top_left++)
    {
        generation_move = piece_coordinate + (top_left * 7);
        if ((generation_move + 1) % 8 != 0 && generation_move < 64)
        {
            queen_moves[move_number_queen] = generation_move;
            move_number_queen++;

            // check if there is a piece
            if (board[generation_move] != 45)
            {
                break;
            }
        }
        else
            break;
    }
    // generate moves top right
    for (int top_right = 1; top_right < 8; top_right++)
    {
        generation_move = piece_coordinate + (top_right * 9);
        if (generation_move % 8 != 0 && generation_move < 64)
        {
            queen_moves[move_number_queen] = generation_move;
            move_number_queen++;

            // check if there is a piece
            if (board[generation_move] != 45)
            {
                break;
            }
        }
        else
            break;
    }
    // generate moves bottom left
    for (int bottom_left = 1; bottom_left < 8; bottom_left++)
    {
        generation_move = piece_coordinate - (bottom_left * 9);
        if ((generation_move + 1) % 8 != 0 && generation_move > 0)
        {
            queen_moves[move_number_queen] = generation_move;
            move_number_queen++;

            // check if there is a piece
            if (board[generation_move] != 45)
            {
                break;
            }
        }
        else if (generation_move == 0)
        {
            queen_moves[move_number_queen] = generation_move;
            move_number_queen++;
            break;
        }
        else
            break;
    }
    // generate moves bottom right
    for (int bottom_right = 1; bottom_right < 8; bottom_right++)
    {
        generation_move = piece_coordinate - (bottom_right * 7);
        if ((generation_move) % 8 != 0 && generation_move > 0)
        {
            queen_moves[move_number_queen] = generation_move;
            move_number_queen++;

            // check if there is a piece
            if (board[generation_move] != 45)
            {
                break;
            }
        }
        else
            break;
    }
    // generate moves top
    for (int top = 1; top < 8; top++)
    {
        generation_move = piece_coordinate + (top * 8);
        if (generation_move < 64)
        {
            queen_moves[move_number_queen] = generation_move;
            move_number_queen++;

            // check if there is a piece
            if (board[generation_move] != 45)
            {
                break;
            }
        }
        else
            break;
    }
    // generate moves bottom
    for (int bottom = 1; bottom < 8; bottom++)
    {
        generation_move = piece_coordinate - (bottom * 8);
        if (generation_move >= 0)
        {
            queen_moves[move_number_queen] = generation_move;
            move_number_queen++;

            // check if there is a piece
            if (board[generation_move] != 45)
            {
                break;
            }
        }
        else
            break;
    }

    // generate moves right
    if ((piece_coordinate + 1) % 8 != 0)
    {
        for (int right = 1; right < 8; right++)
        {
            generation_move = piece_coordinate + right;
            if ((generation_move + 1) % 8 != 0)
            {
                queen_moves[move_number_queen] = generation_move;
                move_number_queen++;

                // check if there is a piece
                if (board[move_number_queen] != 45)
                {
                    break;
                }
            }
            else
            {
                queen_moves[move_number_queen] = generation_move;
                move_number_queen++;
                break;
            }
        }
    }
    // generate moves left
    if (piece_coordinate % 8 != 0)
    {
        for (int left = 1; left < 8; left++)
        {
            generation_move = piece_coordinate - left;
            if ((generation_move) % 8 != 0)
            {
                queen_moves[move_number_queen] = generation_move;
                move_number_queen++;

                // check if there is a piece
                if (board[move_number_queen] != 45)
                {
                    break;
                }
            }
            else
            {
                queen_moves[move_number_queen] = generation_move;
                move_number_queen++;
                break;
            }
        }
    }
}

void check_queen(char *board)
{
    int moves = 0;
    for (int i = 0; i < 64; i++)
    {
        queen_moves_generation(board, i);
        for (int j = 0; j < 27; j++)
        {
            if (queen_moves[j] != 65)
            {
                moves++;
                // printf("%i ", queen_moves[j]);
            }
        }
    }
    printf("%i\n", moves);
}
