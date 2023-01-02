#include "structs.h"

/*
    Creates the post.
    Returns:
        0 -> not logged in.
        1 -> ok
*/
int create_post(char* content, User* author, int num_of_posts_created, PNode* head);

/*
    Likes the given post.
    Returns:
        -2 => post not found
        -1 => not logged in
        0  => already liked
        1  => ok
*/
int like_post(int post_id, User** current_user, LNode* like_head, PNode* post_head);

// Deletes likes of given post, used in delete_post().
void delete_likes_of_post(int post_id, LNode* head);

/*
    the important thing about this function is that it does delete
    the likes of given post as well.
    Returns:
        -1 => not the author or post not found
        0  => not logged in
        1  => ok
*/
int delete_post(int post_id, User** current_user, PNode* post_head, LNode* like_head);

// get the number of likes of a post.
int get_num_of_likes_from_post(int post_id, LNode* like_head);

// get the number of posts a user have liked.
int get_num_of_likes_from_user(User* user, LNode* like_head);

/*
    Does the search for post with given id.
    Returns:
        NULL  => no match
        Post* => ok
*/
Post* find_post(int post_id, PNode* post_head);