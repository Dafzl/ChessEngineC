extern void move_gen(int square, char *board);
// extern char board[64];
extern int user_color;
extern int possible_moves[28];

char choose_color()
{
    int valid = 0;
    char color[10];
    while (valid == 0)
    {
        printf("Choose your pieces: W or B? ");
        scanf("%s", color);
        color[0] = tolower(color[0]);
        valid = (color[0] == 'w' || color[0] == 'b') ? 1 : 0;
    }
    return (color[0] == 'w') ? 1 : 0;
}

int valid_coordinate(char *coordinate_letter, int *coordinate_number);
void move_pieces(char *board)
{
    int coordinate_number, psquare, msquare, valid_piece = 0, valid_move = 0, move_exists = 0;
    char coordinate_letter, piece;
choose_piece:
    do /*choose piece algorithm*/
    {
        printf("Choose piece: ");
        scanf(" %c%i", &coordinate_letter, &coordinate_number);
        coordinate_letter = tolower(coordinate_letter); /*turn to lowercase for user input coordinate errors*/
    } while (!valid_coordinate(&coordinate_letter, &coordinate_number));
    psquare = coordinate_number * 8 + coordinate_letter;
    if (board[psquare] != '-' && (user_color != 0 ? islower(board[psquare]) : 0))
    {
        piece = board[psquare];
        move_gen(psquare, board);
    }
    else
    {
        printf("Choose your own piece!\n");
        goto choose_piece;
    }
choose_move:
    do /*choose move alogrithm*/
    {
        printf("Choose move: ");
        scanf(" %c%i", &coordinate_letter, &coordinate_number);
        coordinate_letter = tolower(coordinate_letter); /*turn to lowercase for user input coordinate errors*/
    } while (!valid_coordinate(&coordinate_letter, &coordinate_number));
    msquare = coordinate_number * 8 + coordinate_letter;
    for (int i = 0; i < 28; i++)
    {
        printf("%i ", possible_moves[i]);
        if (possible_moves[i] == msquare)
        {
            move_exists = 1;
        }
    }
    if (move_exists == 1)
    {
        board[psquare] = '-';
        board[msquare] = piece;
    }
    else
    {
        printf("Move not possible!\n");
        goto choose_piece;
    }
}

int valid_coordinate(char *coordinate_letter, int *coordinate_number)
{
    *coordinate_letter = *coordinate_letter - 97; /*change letter to number for board array*/
    (*coordinate_number)--;                       /*substract 1 for board array begins with 0*/
    return (0 <= *coordinate_letter && 0 <= *coordinate_number && *coordinate_letter < 8 && *coordinate_number < 8) ? 1 : 0;
}
