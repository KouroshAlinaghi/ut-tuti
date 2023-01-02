#include "structs.h"

/*
    Searches for a user with given username.
    Returns:
        NULL  => no match
        USER* => ok
*/
User* find_user(UNode* head, char* username);

/*
  Creates the user but doesnt logs the user in.
  Returns:
    -1 => already logged in
    0  => username already taken
    1  => sign up successfull
*/
int sign_up(char* username, char* password, UNode* head, User** current_user);

/*
    Logs the user in, literally what the name says.
    Returns:
        -1 => already logged in
        0  => wrong credentials
        1  => login successfull
*/
int login(char* username, char* password, User** current_user, UNode* head);

/*
    Logs out of the account.
    Returns:
        0 -> already logged out.
        1 -> ok
*/
int logout(User** current_user);