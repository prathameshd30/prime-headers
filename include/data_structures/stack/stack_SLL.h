#ifndef STACK_SLL_H
#define STACK_SLL_H

#include "../linked_list/singly_linked_list.h"

#define DEFINE_STACK_SLL(NAME, NODE_NAME,TYPE)\
DEFINE_SINGLY_LINKED_LIST_NODE(NODE_NAME, TYPE)\
struct NAME{\
    NODE_NAME* top;\
};\
typedef struct NAME NAME;\
NAME* new_##NAME(void){\
    NAME* obj = malloc(sizeof(NAME));\
    obj->top = NULL;\
    return obj;\
}\
bool isEmpty_##NAME(NAME* obj){\
    if(!obj){\
        return false;\
    }\
    if(!obj->top){\
        return true;\
    }\
    return false;\
}\
bool push_##NAME(NAME* obj, TYPE val){\
    if(!obj){\
        return false;\
    }\
    NODE_NAME* newNode = new_##NODE_NAME(val, obj->top);\
    if(!newNode){\
        return false;\
    }\
    obj->top = newNode;\
    return true;\
}\
bool top_##NAME(NAME* obj, TYPE* return_param){\
    if(!obj || isEmpty_##NAME(obj)){\
        return false;\
    }\
    *return_param = obj->top->val;\
    return true;\
}\
bool pop_##NAME(NAME* obj, bool (*delete_type)(TYPE)){\
    if(!obj || isEmpty_##NAME(obj)){\
        return false;\
    }\
    NODE_NAME* temp = obj->top;\
    obj->top = obj->top->next;\
    if(delete_type){\
        delete_type(temp->val);\
    }\
    free(temp);\
    return true;\
}\
bool delete_##NAME(NAME* obj, bool (*delete_element)(TYPE)){\
    if(!obj){\
        return false;\
    }\
    delete_SLL_##NODE_NAME(&obj->top,delete_element);\
    return true;\
}\
void print_##NAME(NAME* obj, void (*print_element)(TYPE)){\
    if(obj->top == NULL){\
        return;\
    }\
    NODE_NAME* temp = obj->top;\
    while(temp!=NULL){\
        print_element(temp->val);\
        temp = temp->next;\
    }\
}\

#endif