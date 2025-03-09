int pawn = 10, knight = 30, bishop = 33, rook = 50, queen = 90, king = 9999;

int eval(char *board)
{
    int evaluation = 0;
    for (int i = 0; i < 64; i++)
    {
        switch (tolower(board[i]))
        {
        case 'p':
            evaluation = (islower(board[i])) ? (evaluation + pawn) : (evaluation - pawn);
            break;
        case 'n':
            evaluation = (islower(board[i])) ? (evaluation + knight) : (evaluation - knight);
            break;
        case 'b':
            evaluation = (islower(board[i])) ? (evaluation + bishop) : (evaluation - bishop);
            break;
        case 'r':
            evaluation = (islower(board[i])) ? (evaluation + rook) : (evaluation - rook);
            break;
        case 'q':
            evaluation = (islower(board[i])) ? (evaluation + queen) : (evaluation - queen);
            break;
        case 'k':
            evaluation = (islower(board[i])) ? (evaluation + king) : (evaluation - king);
            break;
        default:
            break;
        }
    }
    return evaluation;
}