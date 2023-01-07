// returns a char* to line entered.
char *read_line();

// returns size of the given str.
int get_size(char* str);

/*
    returns a conventional number, based on command
    returns -1 in case the command was not found.
*/
int get_code_from_command(char* command);

/*
    splits the given line's arguments to arg_tokens, and
    also changes command_code to entered command's code.
    Returns number of arguments
*/
int split_commands(char* line, char** arg_tokens, int* command_code);