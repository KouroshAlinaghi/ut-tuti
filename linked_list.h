#include "structs.h"

UNode* initialize_user_linked_list();
PNode* initialize_post_linked_list();
LNode* initialize_like_linked_list();

void u_push(UNode* head, User* user);
void p_push(PNode* head, Post* post);
void l_push(LNode* head, Like* like);