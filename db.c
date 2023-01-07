#include <stdio.h>

#include "structs.h"
#include "social.h"

#define USERS_FILE "accounts.txt"
#define POSTS_FILE "posts.txt"

/*
    Creates/Opens the file
*/
FILE* initialize_users_file() {
    FILE* db = fopen(USERS_FILE, "w");
    return db;
}

/*
    Creates/Opens the file
*/
FILE* initialize_posts_file() {
    FILE* db = fopen(POSTS_FILE, "w");
    return db;
}

/*
    Inserts a new user to the file
*/
void insert_user(FILE* file, User* user, int num_of_posts) {
    fprintf(file, "%s %s %d\n", user->username, user->password, num_of_posts);
    // printf("%s %s %d\n", user->username, user->password, num_of_posts);
}

/*
    Inserts a new post to the file
*/
void insert_post(FILE* file, Post* post, int num_of_likes) {
    fprintf(file, "%s %s %d\n", post->content, post->author->username, num_of_likes);
    // printf("%s %s %d\n", post->content, post->author->username, num_of_likes);
}

/*
    Inserts all of the users
*/
void regenerate_users(FILE* file, UNode* u_head, PNode* p_head) {
    // First, we clear the contents of the file:
    file = freopen(NULL, "w", file);

    UNode* curr = u_head;
    while (curr = curr->next)
        insert_user(file, curr->data, get_number_of_posts(curr->data, p_head)); 
}

/*
    Inserts all of the posts
*/
void regenerate_posts(FILE* file, UNode* u_head, PNode* p_head, LNode* l_head) {
    // First, we clear the contents of the file:
    file = freopen(NULL, "w", file);

    UNode* curr_user = u_head;
    while (curr_user = curr_user->next) {
        PNode* curr_post = p_head;
        while (curr_post = curr_post->next) {
            if (curr_post->data->author == curr_user->data)
                insert_post(file, curr_post->data, get_num_of_likes_from_post(curr_post->data->id, l_head));
        }
    }
}