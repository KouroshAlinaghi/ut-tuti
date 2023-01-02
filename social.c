#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdlib.h>

#include "structs.h"

/*
    Creates the post.
    Returns:
        0 -> not logged in.
        1 -> ok
*/
int create_post(char* content, User* author, int num_of_posts_created, PNode* head) {
    if (author == NULL)
        return 0;

    Post* post = (Post*)malloc(sizeof(Post));
    post->id = num_of_posts_created+1;
    post->author = author;
    post->content = content;

    p_push(head, post);

    return 1;
}

/*
    Likes the given post.
    Returns:
        -2 => post not found
        -1 => not logged in
        0  => already liked
        1  => ok
*/
int like_post(int post_id, User** current_user, LNode* like_head, PNode* post_head) {
    if (*current_user == NULL)
        return -1;

    // First, we check if there is any post with given post_id
    PNode* current_post = post_head;
    int posts_found = 0;
    while (current_post = current_post->next) {
        if (current_post->data->id == post_id) {
            posts_found++;
            break;
        }
    }

    if (posts_found == 0)
        return -2;

    // Then, we make sure that current user hasn't liked the post already
    LNode* current_like = like_head;
    while (current_like = current_like->next) {
        if (current_like->data->post_id == post_id && current_like->data->user == *current_user)
            return 0;
    }

    // Initializing and creating the like
    Like* like = (Like*)malloc(sizeof(Like));
    like->post_id = post_id;
    like->user = *current_user;

    l_push(like_head, like);

    return 1;
};

// Deletes likes of given post, used in delete_post().
void delete_likes_of_post(int post_id, LNode* head) {
    while (head && head->data->post_id == post_id) {
        LNode* tmp = head;
        head = head->next;
        free(tmp);
    }
    
    // remove non-initial matching elements
    // loop invariant: "current != NULL && current->data != key"
    for (LNode* current=head; current!=NULL; current=current->next) {
        while (current->next != NULL && current->next->data->post_id == post_id) {
            LNode* tmp = current->next;
            current->next = tmp->next;
            free(tmp);
        }
    }
}

/*
    the important thing about this function is that it does delete
    the likes of given post as well.
    Returns:
        -1 => not the author or post not found
        0  => not logged in
        1  => ok
*/
int delete_post(int post_id, User** current_user, PNode* post_head, LNode* like_head) {
    if (*current_user == NULL)
        return 0;

    // Iterating over linked list, checking username and password
    PNode* current = post_head;
    PNode* prev = post_head;
    while (current = current->next) {
        if (current->data->id == post_id && current->data->author == *current_user) {
            prev->next = current->next;

            free(current->data->content);
            free(current->data);
            free(current);

            delete_likes_of_post(post_id, like_head);

            return 1;
        }

        prev = current;
    }

    return -1;
};

// get the number of likes of a post.
int get_num_of_likes_from_post(int post_id, LNode* like_head) {
    LNode* current_like = like_head;
    int likes_count = 0;
    while (current_like = current_like->next) {
        if (current_like->data->post_id == post_id)
            likes_count++;
    }

    return likes_count;
}

// get the number of posts a user have liked.
int get_num_of_likes_from_user(User* user, LNode* like_head) {
    LNode* current_like = like_head;
    int likes_count = 0;
    while (current_like = current_like->next) {
        if (current_like->data->user == user)
            likes_count++;
    }

    return likes_count;
}

/*
    Does the search for post with given id.
    Returns:
        NULL  => no match
        Post* => ok
*/
Post* find_post(int post_id, PNode* post_head) {
    PNode* current = post_head;
    while (current = current->next) {
        if (current->data->id == post_id) 
            return current->data;
    }

    return NULL;
}