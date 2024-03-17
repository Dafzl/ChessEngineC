#include "functions/printboard.c"
#include "functions/output.c"
#include "functions/game_ends.c"

// printboard.c
void printboard(char *board);

// userinput.c
char *output(char *board, bool whitetomove);
bool changetomove(bool whitetomove);

// game_ends.c
bool game_end(char *board);
