// decleration
void bishop_moves_generation(char *board, int piece_coordinate);
void check_bishop(char *board);

// variables
int bishop_moves[13];
int move_number_bishop, generation_move;

void bishop_moves_generation(char *board, int piece_coordinate)
{
    // reset bishop_moves, move_number_bishop and generation_move
    move_number_bishop = 0;
    generation_move = 65;
    for (int i = 0; i < 13; i++)
    {
        bishop_moves[i] = 65;
    }

    // generate moves top left
    for (int top_left = 1; top_left < 8; top_left++)
    {
        generation_move = piece_coordinate + (top_left * 7);
        if ((generation_move + 1) % 8 != 0 && generation_move < 64)
        {
            bishop_moves[move_number_bishop] = generation_move;
            move_number_bishop++;

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
            bishop_moves[move_number_bishop] = generation_move;
            move_number_bishop++;

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
            bishop_moves[move_number_bishop] = generation_move;
            move_number_bishop++;

            // check if there is a piece
            if (board[generation_move] != 45)
            {
                break;
            }
        }
        else if (generation_move == 0)
        {
            bishop_moves[move_number_bishop] = generation_move;
            move_number_bishop++;
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
            bishop_moves[move_number_bishop] = generation_move;
            move_number_bishop++;

            // check if there is a piece
            if (board[generation_move] != 45)
            {
                break;
            }
        }
        else
            break;
    }
}

void check_bishop(char *board)
{
    int moves = 0;
    for (int i = 0; i < 64; i++)
    {
        bishop_moves_generation(board, i);
        for (int j = 0; j < 13; j++)
        {
            if (bishop_moves[j] != 65)
            {
                moves++;
                // printf("%i ", bishop_moves[j]);
            }
        }
    }
    printf("%i\n", moves);
}
