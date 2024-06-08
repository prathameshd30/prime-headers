/**
 * @file doubly_linked_list.h
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-06-01
 * 
 * 
 */
#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <stdbool.h>

#define DEFINE_DLL_NODE(NAME,TYPE)\
struct NAME{\
    TYPE val;\
    struct NAME* next;\
    struct NAME* prev;\
};\
typedef struct NAME NAME;\
NAME* new_##NAME(TYPE val, NAME* next, NAME* prev){\
    NAME* obj = malloc(sizeof(NAME));\
    if(!obj){\
        return NULL;\
    }\
    obj->val = val;\
    obj->next = next;\
    obj->prev = prev;\
    return obj;\
}\
bool insert_at_head_DLL_##NAME(NAME** head, TYPE val){\
    if(!head || !*head){\
        return false;\
    }\
    NAME* obj = new_##NAME(val, *head,NULL);\
    if(!obj){\
        return false;\
    }\
    *head = obj;\
    return true;\
}\
bool insert_after_node_DLL_##NAME(NAME* node, TYPE val){\
    if(!node){\
        return false;\
    }\
    NAME* obj = new_##NAME(val,node->next,node);\
    if(!obj){\
        return false;\
    }\
    if(node->next){\
        node->next->prev = obj;\
    }\
    node->next = obj;\
    return true;\
}\
bool insert_at_end_DLL_##NAME(NAME* head, TYPE val){\
    if(!head){\
        return false;\
    }\
    while(head->next){\
        head = head->next;\
    }\
    if(!insert_after_node_DLL_##NAME(head,val)){\
        return false;\
    }\
    return true;\
}\
bool remove_node_DLL_##NAME(NAME* node, TYPE* val, bool (*delete_element)(TYPE)){\
    if(!node){\
        return false;\
    }\
    if(node->prev){\
        node->prev->next = node->next;\
    }\
    if(node->next){\
        node->next->prev = node->prev;\
    }\
    if(val){\
        *val = node->val;\
    }\
    else if(delete_element){\
        delete_element(node->val); /*should there be error checking for delete_element?, if so how? */\
    }\
    free(node);\
    return true;\
}\
bool remove_from_end_DLL_##NAME(NAME* head, TYPE* val, bool (*delete_element)(TYPE)){\
    if(!head){\
        return false;\
    }\
    while(head->next){\
        head = head->next;\
    }\
    if(!remove_node_DLL_##NAME(head,val,delete_element)){\
        return false;\
    }\
    return true;\
}\
bool remove_from_beginning_##NAME(NAME** head, TYPE* val, bool (*delete_element)(TYPE)){\
    if(!head || !(*head)){\
        return false;\
    }\
    NAME* node = *head;\
    *head = node->next;\
    if(val){\
        *val = node->val;\
    }\
    else if(delete_element){\
        delete_element(node->val);\
    }\
    free(node);\
    return true;\
}\
bool delete_DLL_##NAME(NAME* head, bool (*delete_element)(TYPE)){\
    NAME* tempNext;\
    while(head){\
        tempNext = head->next;\
        if(delete_element){\
            delete_element(head->val);/*Error checking? if so how?*/\
        }\
        free(head);\
        head = tempNext;\
    }\
    return true;\
}\
void print_DLL_##NAME(NAME* head, void(*print_element)(TYPE)){\
    while(head){\
        print_element(head->val);\
        head = head->next;\
    }\
    return;\
}\


#endif