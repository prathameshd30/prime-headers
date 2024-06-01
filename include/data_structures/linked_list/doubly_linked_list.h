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
#include <stdint.h>

#define DEFINE_DLL_NODE(NAME,TYPE)\
struct NAME{\
    TYPE val;\
    struct NAME* next;\
    struct NAME* prev;\
}\
typedef struct NAME NAME;\
NAME* new_##NAME(TYPE val, NAME* next, NEXT* prev){\
    NAME* obj = malloc(sizeof(NAME));\
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
    *head = obj;\
    return true;\
}\
bool insert_after_DLL_##NAME(NAME* node, TYPE val){\
    if(!node){\
        return false;\
    }\
    NAME* obj = new_##NAME(val,node->next,node);\
    if(node->next){\
        node->next->prev = obj;\
    }\
    node->next = obj;\
    return true;\
}\
bool remove_node_DLL_##NAME(NAME* node, TYPE* val, bool (*delete_element)(TYPE)){\
    node->prev->next = node->next;\
    node->next->prev = node->prev;\
    if(val){\
        *val = node->val;\
    }\
    else{\
        delete_element(node->val);\
    }\
    free(node);\
    return true;\
}\





#endif