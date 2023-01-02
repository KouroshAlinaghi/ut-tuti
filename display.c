#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

// prints post_ids of given users's posts.
void print_post_ids_of_given_user(User* user, PNode* post_head) {
    PNode* current_post = post_head;
    while (current_post = current_post->next) {
        if (current_post->data->author == user)
            printf("%d ", current_post->data->id);
    }
    printf("\n");
}

// prints a posts information
void print_post_info(Post* post, LNode* like_head) {
    printf("\n");
    printf("Author: %s\n", post->author->username);
    printf("Post ID: %d\n", post->id);
    printf("Likes: %d\n", get_num_of_likes_from_post(post->id, like_head));
    printf("Content: %s\n", post->content);
}

/*
    Prints current user's username, password, post_ids
    created by them and number of posts they've liked.
    Returns:
        0 => not logged in
        1 => ok
*/
int print_current_user_info(User** current_user, PNode* post_head, LNode* like_head) {
    if (*current_user == NULL)
        return 0;   

    printf("\n");
    printf("Username: %s\n", (*current_user)->username);
    printf("Password: %s\n", (*current_user)->password);
    printf("Posts created by you:\t");
    print_post_ids_of_given_user(*current_user, post_head);
    printf("Number of posts you've liked: %d\n", get_num_of_likes_from_user(*current_user, like_head));

    return 1;
}

// no.
int print_other_user_info(User* user, PNode* post_head, LNode* like_head) {
    if (user == NULL)
        return 0;   

    printf("\n");
    printf("Posts created by %s:\t", user->username);
    print_post_ids_of_given_user(user, post_head);
    printf("Number of posts liked by %s: %d\n", user->username, get_num_of_likes_from_user(user, like_head));

    return 1;
}