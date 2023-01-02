#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdio.h>
#include <stdlib.h>

#include "cli.h"
#include "linked_list.h"

#define MSG_MAX_SIZE 100

int main() {
    User* current_user = NULL;
    int num_of_posts_created = 0;
    UNode* u_head = initialize_user_linked_list();
    PNode* p_head = initialize_post_linked_list();
    LNode* l_head = initialize_like_linked_list();
    char msg[MSG_MAX_SIZE] = "Hello and welcome to UT-TUTI";
    int result = 1;

    while (1) {
        printf("%s\n", msg);
        if (current_user)
            printf("#");
        if (result) {
            printf("\033[1;32m");
            printf("> ");
        }
        else {
            printf("\033[1;31m");
            printf("> ");
        }
        printf("\033[0m");
        result = start_cli(msg, u_head, p_head, l_head, &current_user, &num_of_posts_created);
    }

    // hehe the program never gets here, hehe
    return 0;
}