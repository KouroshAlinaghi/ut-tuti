#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structs.h"
#include "social.h"
#include "account.h"
#include "parser.h"

#define NUMBER_OF_COMMANDS 10
#define MAX_NUMBER_OF_ARGUMENTS 2

/*
    executes the given command with given arguments.
    returns 1 if successfull, 0 if unsuccessfull,
    and also modifies msg.
*/
int execute(int command_code, char** args, char* msg, UNode* u_head, PNode* p_head, LNode* l_head, User** current_user, int* num_of_posts_created) {
    switch (command_code) {
        case 0:
            switch (sign_up(args[0], args[1], u_head, current_user)) {
                case -1: // already logged in.
                    strcpy(msg, "You are already logged in, please logout to sign up.");
                    free(args[0]);
                    free(args[1]);
                    return 0;
                case 0: // username exists
                    strcpy(msg, "The username you entered is already taken.");
                    free(args[0]);
                    free(args[1]);
                    return 0;
                case 1: // ok
                    login(args[0], args[1], current_user, u_head);
                    strcpy(msg, "Sign up successfull, logged in.");
                    return 1;
            }
        case 1:
            switch (login(args[0], args[1], current_user, u_head)) {
                case -1: // already logged in.
                    strcpy(msg, "You are already logged in.");
                    free(args[0]);
                    free(args[1]);
                    return 0;
                case 0: // wrong credentials
                    strcpy(msg, "Wrong username or password.");
                    free(args[0]);
                    free(args[1]);
                    return 0;
                case 1: // ok
                    strcpy(msg, "Logged in successfully.");
                    free(args[0]);
                    free(args[1]);
                    return 1;
            }
        case 2:
            if (create_post(args[0], *current_user, *num_of_posts_created, p_head)) {
                (*num_of_posts_created)++;
                strcpy(msg, "Published post successfully.");
                return 1;
            } else {
                free(args[0]);
                strcpy(msg, "Please login to publish a post.");
                return 0;
            }
            break;
        case 3:
            switch (like_post(atoi(args[1]), current_user, l_head, p_head)) {
                case -2: // post not found
                    free(args[0]);
                    free(args[1]);
                    strcpy(msg, "Could not find post with given id.");
                    return 0;
                case -1: // not logged in
                    free(args[0]);
                    free(args[1]);
                    strcpy(msg, "Please login to like a post.");
                    return 0;
                case 0: // already like
                    free(args[0]);
                    free(args[1]);
                    strcpy(msg, "You've already liked this post.");
                    return 0;
                case 1: // ok
                    free(args[0]);
                    free(args[1]);
                    strcpy(msg, "Liked post successfully.");
                    return 1;
            }
        case 4:
            if (logout(current_user)) {
                strcpy(msg, "Logged out successfully.");
                return 1;
            } else {
                strcpy(msg, "You're not logged in.");
                return 0;
            }
        case 5:
            switch (delete_post(atoi(args[0]), current_user, p_head, l_head)) {
                case -1:
                    free(args[0]);
                    strcpy(msg, "You either don't own the post or the post doesn't exist.");
                    return 0;
                case 0:
                    free(args[0]);
                    strcpy(msg, "Please login first.");
                    return 0;
                case 1:
                    free(args[0]);
                    strcpy(msg, "Deleted post successfully.");
                    return 1;
            }
        case 6:
            if (print_current_user_info(current_user, p_head, l_head)) {
                strcpy(msg, "");
                return 1;
            } else {
                strcpy(msg, "Please login first.");
                return 0;
            }
        case 7:
            User* user = find_user(u_head, args[0]);
            if (user == NULL) {
                free(args[0]);
                strcpy(msg, "Could not find user with given username.");
                return 0;
            }
            if (print_other_user_info(user, p_head, l_head)) {
                free(args[0]);
                strcpy(msg, "");
                return 1;
            }
        case 8:
            Post* post = find_post(atoi(args[0]), p_head);
            if (post) {
                strcpy(msg, "");
                print_post_info(post, l_head);
                free(args[0]);
                return 1;
            } else {
                strcpy(msg, "Couldn't find post with given id.");
                free(args[0]);
                return 0;
            }
        case 9:
            exit(0);
    }

}

// Does everything, from reading input to executing the command.
int start_cli(char* msg, UNode* u_head, PNode* p_head, LNode* l_head, User** current_user, int* num_of_posts_created) {
    char* input = read_line();
    int command_code;
    char* args[MAX_NUMBER_OF_ARGUMENTS];
    int number_of_arguments = split_commands(input, args, &command_code);
    if (number_of_arguments == -1) {
        strcpy(msg, "Please enter a valid command, not just empty spcaes!");
        return 0;
    }
    int number_of_args_per_command[NUMBER_OF_COMMANDS] = {2, 2, 1, 2, 0, 1, 0, 1, 1, 0};
    if (command_code == -1) {
        strcpy(msg, "Unknown command, please enter a valid one.");
        return 0;
    }
    if (number_of_args_per_command[command_code] != number_of_arguments) {
        strcpy(msg, "Wrong number of arguments");
        return 0;
    }
    return execute(command_code, args, msg, u_head, p_head, l_head, current_user, num_of_posts_created);
}