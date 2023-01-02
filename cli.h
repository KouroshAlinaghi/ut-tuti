#include "structs.h"

/*
    executes the given command with given arguments.
    returns 1 if successfull, 0 if unsuccessfull,
    and also modifies msg.
*/
int execute(int command_code, char** args, char* msg, UNode* u_head, PNode* p_head, LNode* l_head, User** current_user, int* num_of_posts_created);

// Does everything, from reading input to executing the command.
int start_cli(char* msg, UNode* u_head, PNode* p_head, LNode* l_head, User** current_user, int* num_of_posts_created);