#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdio.h>
#include <stdlib.h>

#include "cli.h"
#include "linked_list.h"
#include "db.h"

#define MSG_MAX_SIZE 100

int main() {
    User* current_user = NULL;
    int num_of_posts_created = 0, result = 1;
    char msg[MSG_MAX_SIZE] = "Hello and welcome to UT-TUTI";
    UNode* u_head = initialize_user_linked_list();
    PNode* p_head = initialize_post_linked_list();
    LNode* l_head = initialize_like_linked_list();
    FILE* users_db;
    FILE* posts_db;

    while (1) {
        users_db = initialize_users_file();
        posts_db = initialize_posts_file();
        printf("%s\n", msg);
        if (current_user)
            printf("#");
        if (result) {
            regenerate_users(users_db, u_head, p_head);
            regenerate_posts(posts_db, u_head, p_head, l_head);
            printf("\033[1;32m"); // green
            printf("> ");
        } else {
            printf("\033[1;31m"); // red
            printf("> ");
        }
        printf("\033[0m");
        fclose(users_db);
        fclose(posts_db);
        result = start_cli(msg, u_head, p_head, l_head, &current_user, &num_of_posts_created);
    }

    // hehe the program never gets here, hehe
    return 0;
}