#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUMBER_OF_ARGUMENTS 2

// returns a char* to line entered.
char *read_line() {
    int counter = 0;
    char c = getchar();
    char *str = (char*)malloc(sizeof(char));
    while (c != '\n') {
        str[counter] = c;
        str = realloc(str, sizeof(char) + counter + 1);
        c = getchar();
        counter++;
    }
    str[counter] = '\0';

    return str;
}

// returns size of the given str.
int get_size(char* str) {
    int size;
    for (size=0; str[size]!='\0'; size++);
    return size;
}

/*
    returns a conventional number, based on command
    returns -1 in case the command was not found.
*/
int get_code_from_command(char* command) {
    if (strcmp(command, "signup") == 0)
        return 0;
    else if (strcmp(command, "login") == 0)
        return 1;
    else if (strcmp(command, "post") == 0)
        return 2;
    else if (strcmp(command, "like") == 0)
        return 3;
    else if (strcmp(command, "logout") == 0)
        return 4;
    else if (strcmp(command, "delete") == 0)
        return 5;
    else if (strcmp(command, "info") == 0)
        return 6;
    else if (strcmp(command, "find_user") == 0)
        return 7;
    else if (strcmp(command, "show") == 0)
        return 8;
    else 
        return -1;
}

/*
    splits the given line's arguments to arg_tokens, and
    also changes command_code to entered command's code.
*/
void split_commands(char* line, char** arg_tokens, int* command_code) {
    char* str, *token, *to_be_freed;
    to_be_freed = str = strdup(line); 

    int arg_tokens_found = 0;
    
    // Fetching command
    char* command = strsep(&str, " ");
    *command_code = get_code_from_command(command);

    // delimiter for spliting is '\n' if command is post.
    char delimiter[1];
    delimiter[0] = *command_code == 2 ? '\n' : ' ';
    
    // loop through the string to extract all arguments
    int current_token_size = 0;
    while ((token = strsep(&str, delimiter)) && arg_tokens_found <= MAX_NUMBER_OF_ARGUMENTS) {
        current_token_size = get_size(token);
        arg_tokens[arg_tokens_found] = (char*)malloc((current_token_size+1)*sizeof(char));
        strcpy(arg_tokens[arg_tokens_found], token);
        arg_tokens_found++;
    }

    free(to_be_freed);
}