#include "structs.h"

// prints post_ids of given users's posts.
void print_post_ids_of_given_user(User* user, PNode* post_head);

// prints a posts information
void print_post_info(Post* post, LNode* like_head);

/*
    Prints current user's username, password, post_ids
    created by them and number of posts they've liked.
    Returns:
        0 => not logged in
        1 => ok
*/
int print_current_user_info(User** current_user, PNode* post_head, LNode* like_head);

// no.
int print_other_user_info(User* user, PNode* post_head, LNode* like_head);