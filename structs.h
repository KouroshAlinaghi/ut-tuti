#ifndef HEADERFILE
#define HEADERFILE

typedef struct User {
    char* username;
    char* password;
} User;

typedef struct Post {
    int id;
    User* author;
    char* content;
} Post;

typedef struct Like {
    User* user;
    int post_id;
} Like;

typedef struct UNode {
    User* data;
    struct UNode* next;
} UNode;

typedef struct PNode {
    Post* data;
    struct PNode* next;
} PNode;

typedef struct LNode {
    Like* data;
    struct LNode* next;
} LNode;

#endif