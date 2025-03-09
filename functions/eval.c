#include "pieces/eval_tables.c"
extern int pawnt[64], knightt[64], bishopt[64], rookt[64], queent[64];
int king = 999;
int eval(char *board)
{
    int evaluation = 0;
    for (int i = 0; i < 64; i++)
    {
        switch (tolower(board[i]))
        {
        case 'p':
            evaluation = (islower(board[i])) ? (evaluation + pawnt[63 - i]) : (evaluation - pawnt[i]);
            break;
        case 'n':
            evaluation = (islower(board[i])) ? (evaluation + knightt[i]) : (evaluation - knightt[i]);
            break;
        case 'b':
            evaluation = (islower(board[i])) ? (evaluation + bishopt[i]) : (evaluation - bishopt[i]);
            break;
        case 'r':
            evaluation = (islower(board[i])) ? (evaluation + rookt[i]) : (evaluation - rookt[i]);
            break;
        case 'q':
            evaluation = (islower(board[i])) ? (evaluation + queent[i]) : (evaluation - queent[i]);
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