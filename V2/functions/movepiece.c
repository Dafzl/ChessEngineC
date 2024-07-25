// decleration
char *user(char *board);
char *move_piece(char *board, int begin_square, int move_square);

// variables
int begin_square_number, move_square_number, begin_coordinate_letter, move_coordinate_letter, begin_square, move_square;
char begin_square_letter, move_square_letter;

char *user(char *board)
{
    // get the coordinates
    printf("Choose piece: ");
    scanf(" %c", &begin_square_letter);
    scanf("%i", &begin_square_number);
    printf("Move: ");
    scanf(" %c", &move_square_letter);
    scanf("%i", &move_square_number);

    // turn letters into numbers
    begin_coordinate_letter = begin_square_letter;
    move_coordinate_letter = move_square_letter;

    // turn 2d coordinates into 1d coordinate
    begin_square, move_square;
    begin_square = (begin_coordinate_letter - 65) + (begin_square_number - 1) * 8;
    move_square = (move_coordinate_letter - 65) + (move_square_number - 1) * 8;
    printf("%i %i ", begin_square, move_square);

    char *updated_board = move_piece(board, begin_square, move_square);
    return updated_board;
}

char *move_piece(char *board, int begin_square, int move_square)
{
    board[move_square] = board[begin_square];
    board[begin_square] = '-';
    return board;
}