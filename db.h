#include <stdio.h>

#include "structs.h"
#include "social.h"

/*
    Creates/Opens the file
*/
    FILE* initialize_users_file();
    FILE* initialize_posts_file();


/*
    Inserts a new user/post to the file
*/
    void insert_user(FILE* file, User* user, int num_of_posts);
    void insert_post(FILE* file, Post* post, int num_of_likes);


/*
    Inserts all of the users/posts
*/
    void regenerate_users(FILE* file, UNode* u_head, PNode* p_head);
    void regenerate_posts(FILE* file, UNode* u_head, PNode* p_head, LNode* l_head);