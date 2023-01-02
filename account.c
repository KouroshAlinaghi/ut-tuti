#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdlib.h>
#include <string.h>

#include "structs.h"

/*
    Searches for a user with given username.
    Returns:
        NULL  => no match
        USER* => ok
*/
User* find_user(UNode* head, char* username) {
    UNode* current = head;
    while (current = current->next) {
        if (strcmp(current->data->username, username) == 0) 
            return current->data;
    }

    return NULL;
};

/*
  Creates the user but doesnt logs the user in.
  Returns:
    -1 => already logged in
    0  => username already taken
    1  => sign up successfull
*/
int sign_up(char* username, char* password, UNode* head, User** current_user) {
    if (*current_user != NULL)
        return -1;

    // First, we check that the username is unique
    UNode* current = head;
    while (current = current->next) {
        if (strcmp(current->data->username, username) == 0)
            return 0;
    }

    // Initializing the user
    User* user = (User*)malloc(sizeof(User));
    user->username = username;
    user->password = password;

    // Pushing the user to the end of the linked list
    u_push(head, user);

    return 1;
};

/*
    Logs the user in, literally what the name says.
    Returns:
        -1 => already logged in
        0  => wrong credentials
        1  => login successfull
*/
int login(char* username, char* password, User** current_user, UNode* head) {
    if (*current_user != NULL)
        return -1; // should not login when already logged in

    // Iterating over linked list, checking username and password
    UNode* current = head;
    while (current = current->next) {
        if ((strcmp(current->data->username, username) == 0) && (strcmp(current->data->password, password) == 0)) {
            *current_user = current->data;
            return 1;
        }
    }

    return 0;
}

/*
    Logs out of the account.
    Returns:
        0 -> already logged out.
        1 -> ok
*/
int logout(User** current_user) {
    if (*current_user == NULL)
        return 0;

    *current_user = NULL;
    return 1;
}
