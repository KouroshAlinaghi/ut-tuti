#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdlib.h>

#include "structs.h"

UNode* initialize_user_linked_list() {
    UNode* head = (UNode*)malloc(sizeof(UNode));
    User* head_user = (User*)malloc(sizeof(User));
    
    head->data = head_user;
    head->next = NULL;

    return head;
}

PNode* initialize_post_linked_list() {
    PNode* head = (PNode*)malloc(sizeof(PNode));
    Post* head_post = (Post*)malloc(sizeof(Post));
    
    head->data = head_post;
    head->next = NULL;
    
    return head;
}

LNode* initialize_like_linked_list() {
    LNode* head = (LNode*)malloc(sizeof(LNode));
    Like* head_like = (Like*)malloc(sizeof(Like));
    
    head->data = head_like;
    head->next = NULL;
    
    return head;
}

void u_push(UNode* head, User* user) {
    UNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (UNode*)malloc(sizeof(UNode));
    current->next->data = user;
    current->next->next = NULL;
}

void p_push(PNode* head, Post* post) {
    PNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (PNode*)malloc(sizeof(PNode));
    current->next->data = post;
    current->next->next = NULL;
}

void l_push(LNode* head, Like* like) {
    LNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (LNode*)malloc(sizeof(Like));
    current->next->data = like;
    current->next->next = NULL;
}