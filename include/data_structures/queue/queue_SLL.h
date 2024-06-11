#include <stdio.h>
#include "../linked_list/singly_linked_list.h"

#define DEFINE_QUEUE_SLL(NAME,NODE_NAME,TYPE)\
DEFINE_SINGLY_LINKED_LIST_NODE(NODE_NAME,TYPE)\
struct NAME{\
    NODE_NAME* front;\
    NODE_NAME* rear;\
};\
typedef struct NAME NAME;\
NAME* new_##NAME(void){\
    NAME* obj = malloc(sizeof(NAME));\
    obj->front = NULL;\
    obj->rear = NULL;\
    return obj;\
}\
bool enqueue_##NAME(NAME* obj, TYPE val){\
    if(!obj){\
        return false;\
    }\
    return insert_at_head_SLL_##NODE_NAME(&obj->front, val);\
}\
bool dequeue_##NAME(NAME* obj, TYPE* return_param, bool (*delete_element)(TYPE)){\
    if(!obj){\
        return false;\
    }\
    NODE_NAME* temp = obj->rear;\
    if(return_param){\
        *return_param = obj->rear->val;\
    }\
    else if(delete_element){\
        delete_element(temp->val);\
    }\
    obj->rear = obj->rear->next;\
    free(temp);\
    return true;\
}