#ifdef BINARY_TREE_H
#ifndef BINARY_TREE_ALG_H
#define BINARY_TREE_ALG_H

#include "../../../include/data_structures/vector/vector.h"
#include "../../../include/data_structures/stack/stack_vector.h"
#include "binary_tree.h"

#define DEFINE_BINARY_TREE_ALGOS(NAME, NODE_NAME, TYPE, VECTOR_NAME, STACK_NAME, STACK_VECTOR_NAME)\
DEFINE_BINARY_TREE(NAME, NODE_NAME, TYPE)\
DEFINE_VECTOR(VECTOR_NAME, TYPE)\
DEFINE_STACK_VECTOR(STACK_NAME,STACK_VECTOR_NAME, NODE_NAME*)\
void recursive_inorder_vec_helper_##NODE_NAME(NODE_NAME* node, VECTOR_NAME* vec){\
    if(!node){\
        return;\
    }\
    if(node->left){\
        recursive_inorder_vec_helper_##NODE_NAME(node->left,vec);\
    }\
    add_at_end_##VECTOR_NAME(vec, node->val);\
    if(node->right){\
        recursive_inorder_vec_helper_##NODE_NAME(node->right,vec);\
    }\
}\
VECTOR_NAME* recursive_inorder_vec_##NAME(NAME* obj){\
    VECTOR_NAME* new_vec = new_##VECTOR_NAME(0);\
    recursive_inorder_vec_helper_##NODE_NAME(obj->root, new_vec);\
    return new_vec;\
}\
void recursive_preorder_vec_helper_##NODE_NAME(NODE_NAME* node, VECTOR_NAME* vec){\
    if(!node){\
        return;\
    }\
    add_at_end_##VECTOR_NAME(vec, node->val);\
    if(node->left){\
        recursive_preorder_vec_helper_##NODE_NAME(node->left,vec);\
    }\
    if(node->right){\
        recursive_preorder_vec_helper_##NODE_NAME(node->right,vec);\
    }\
}\
VECTOR_NAME* recursive_preorder_vec_##NAME(NAME* obj){\
    VECTOR_NAME* new_vec = new_##VECTOR_NAME(0);\
    recursive_preorder_vec_helper_##NODE_NAME(obj->root, new_vec);\
    return new_vec;\
}\
void recursive_postorder_vec_helper_##NODE_NAME(NODE_NAME* node, VECTOR_NAME* vec){\
    if(!node){\
        return;\
    }\
    if(node->left){\
        recursive_postorder_vec_helper_##NODE_NAME(node->left,vec);\
    }\
    if(node->right){\
        recursive_postorder_vec_helper_##NODE_NAME(node->right,vec);\
    }\
    add_at_end_##VECTOR_NAME(vec, node->val);\
}\
VECTOR_NAME* recursive_postorder_vec_##NAME(NAME* obj){\
    VECTOR_NAME* new_vec = new_##VECTOR_NAME(0);\
    recursive_postorder_vec_helper_##NODE_NAME(obj->root, new_vec);\
    return new_vec;\
}\
bool print_preorder_##NAME(NAME* obj, void(*print_val)(TYPE), bool(*delete_element)(NODE_NAME*)){\
    STACK_NAME* st = new_##STACK_NAME();\
    push_##STACK_NAME(st, obj->root);\
    NODE_NAME* tempNode;\
    while(!(st->isEmpty)){\
        top_##STACK_NAME(st,&tempNode);\
        pop_##STACK_NAME(st,delete_element);\
        print_val(tempNode->val);\
        if(tempNode->right){\
            push_##STACK_NAME(st,tempNode->right);\
        }\
        if(tempNode->left){\
            push_##STACK_NAME(st,tempNode->left);\
        }\
    }\
    return true;\
}\
bool print_inorder_##NAME(NAME* obj, void(*print_val)(TYPE), bool(*delete_element)(NODE_NAME*)){\
    STACK_NAME* st = new_##STACK_NAME();\
    NODE_NAME* tempNode = obj->root;\
    while(tempNode!=NULL || !(st->isEmpty)){\
        while(tempNode){\
            push_##STACK_NAME(st,tempNode);\
            tempNode = tempNode->left;\
        }\
        top_##STACK_NAME(st,&tempNode);\
        print_val(tempNode->val);\
        pop_##STACK_NAME(st,delete_element);\
        tempNode = tempNode->right;\
    }\
    return true;\
}\

#endif
#endif