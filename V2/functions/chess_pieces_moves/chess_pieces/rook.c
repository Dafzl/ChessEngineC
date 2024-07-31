// decleration
void rook_moves_generation(char *board, int piece_coordinate);
void check_rook(char *board);

// variables
int rook_moves[15];
int move_number_rook, generation_move;

void rook_moves_generation(char *board, int piece_coordinate)
{
    // reset rook_moves, move_number_rook and generation_move
    move_number_rook = 0;
    generation_move = 65;
    for (int i = 0; i < 15; i++)
    {
        rook_moves[i] = 65;
    }

    // generate moves top
    for (int top = 1; top < 8; top++)
    {
        generation_move = piece_coordinate + (top * 8);
        if (generation_move < 64)
        {
            rook_moves[move_number_rook] = generation_move;
            move_number_rook++;

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
            rook_moves[move_number_rook] = generation_move;
            move_number_rook++;

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
                rook_moves[move_number_rook] = generation_move;
                move_number_rook++;

                // check if there is a piece
                if (board[move_number_rook] != 45)
                {
                    break;
                }
            }
            else
            {
                rook_moves[move_number_rook] = generation_move;
                move_number_rook++;
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
                rook_moves[move_number_rook] = generation_move;
                move_number_rook++;

                // check if there is a piece
                if (board[move_number_rook] != 45)
                {
                    break;
                }
            }
            else
            {
                rook_moves[move_number_rook] = generation_move;
                move_number_rook++;
                break;
            }
        }
    }
}

void check_rook(char *board)
{
    int moves = 0;

    for (int i = 0; i < 64; i++)
    {
        rook_moves_generation(board, i);
        for (int j = 0; j < 15; j++)
        {
            if (rook_moves[j] != 65)
            {
                moves++;
                // printf("%i ", rook_moves[j]);
            }
        }
    }

    printf("%i \n", moves);
}
