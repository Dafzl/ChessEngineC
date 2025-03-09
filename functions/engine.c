void engine_move();
void reset_board(char *board, char *eval_board);
extern int possible_moves[28];
int piecetomove, top_move;

void engine(char *board)
{
    int top_eval = 0, evaluation = 0;
    char eval_board[64];
    piecetomove = 65, top_move = 65;
    reset_board(board, eval_board);

    for (int i = 0; i < 64; i++)
    {
        if (isupper(board[i]))
        {
            move_gen(i, board);
            for (int moves = 0; moves < 28; moves++)
            {
                if (possible_moves[moves] != 65)
                {
                    reset_board(board, eval_board);
                    eval_board[possible_moves[moves]] = eval_board[i];
                    eval_board[i] = '-';
                    evaluation = eval(eval_board);
                    if (evaluation <= top_eval)
                    {
                        piecetomove = i;
                        top_move = possible_moves[moves];
                        top_eval = evaluation;
                    }
                }
            }
        }
    }
    // printf("move: %i, eval: %i\n", top_move, top_eval);
}

void reset_board(char *board, char *eval_board)
{
    for (int i = 0; i < 64; i++)
    {
        eval_board[i] = board[i];
    }
}

extern char board[64];
void engine_move()
{
    engine(board);
    board[top_move] = board[piecetomove];
    board[piecetomove] = '-';
}