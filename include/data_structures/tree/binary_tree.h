#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <stdbool.h>

#define DEFINE_BINARY_TREE(NAME, NODE_NAME, TYPE)\
struct NODE_NAME{\
    TYPE val;\
    struct NODE_NAME* left;\
    struct NODE_NAME* right;\
};\
typedef struct NODE_NAME NODE_NAME;\
struct NAME{\
    NODE_NAME* root;\
};\
typedef struct NAME NAME;\
NODE_NAME* new_##NODE_NAME(TYPE val, NODE_NAME* left, NODE_NAME* right){\
    NODE_NAME* obj = malloc(sizeof(NODE_NAME));\
    if(!obj){\
        return NULL;\
    }\
    obj->val = val;\
    obj->left = left;\
    obj->right = right;\
    return obj;\
}\
bool insert_at_left_##NODE_NAME(NODE_NAME* obj, TYPE val, NODE_NAME* left, NODE_NAME* right){\
    if(!obj){\
        return false;\
    }\
    if(obj->left){\
        return false;\
    }\
    NODE_NAME* new_node = new_##NODE_NAME(val,left,right);\
    if(!new_node){\
        return false;\
    }\
    obj->left = new_node;\
    return true;\
}\
bool insert_at_right_##NODE_NAME(NODE_NAME* obj, TYPE val, NODE_NAME* left, NODE_NAME* right){\
    if(!obj){\
        return false;\
    }\
    if(obj->right){\
        return false;\
    }\
    NODE_NAME* new_node = new_##NODE_NAME(val, left, right);\
    if(!new_node){\
        return false;\
    }\
    obj->right = new_node;\
    return true;\
}\
NAME* new_##NAME(TYPE val){\
    NAME* obj = malloc(sizeof(NAME));\
    if(!obj){\
        return NULL;\
    }\
    obj->root = new_##NODE_NAME(val,NULL,NULL);\
    if(!obj->root){\
        free(obj);\
        return NULL;\
    }\
    return obj;\
}\
void print_recursive_inorder_helper_##NODE_NAME(NODE_NAME* node, void (*print_val)(TYPE)){\
    if(!node){\
        return;\
    }\
    if(node->left){\
        print_recursive_inorder_helper_##NODE_NAME(node->left,print_val);\
    }\
    print_val(node->val);\
    if(node->right){\
        print_recursive_inorder_helper_##NODE_NAME(node->right,print_val);\
    }\
    return;\
}\
bool print_recursive_inorder_##NAME(NAME* obj, void (*print_val)(TYPE)){\
    if(!obj){\
        return false;\
    }\
    print_recursive_inorder_helper_##NODE_NAME(obj->root,print_val);\
    return true;\
}\
void print_recursive_preorder_helper_##NODE_NAME(NODE_NAME* obj, void(*print_val)(TYPE)){\
    if(!obj){\
        return;\
    }\
    print_val(obj->val);\
    if(obj->left){\
        print_recursive_preorder_helper_##NODE_NAME(obj->left, print_val);\
    }\
    if(obj->right){\
        print_recursive_preorder_helper_##NODE_NAME(obj->right, print_val);\
    }\
    return;\
}\
bool print_recursive_preorder_##NAME(NAME* obj, void(*print_val)(TYPE)){\
    if(!obj){\
        return false;\
    }\
    print_recursive_preorder_helper_##NODE_NAME(obj->root,print_val);\
    return true;\
}\
void print_recursive_postorder_helper_##NODE_NAME(NODE_NAME* obj, void(*print_val)(TYPE)){\
    if(!obj){\
        return;\
    }\
    if(obj->left){\
        print_recursive_postorder_helper_##NODE_NAME(obj->left, print_val);\
    }\
    if(obj->right){\
        print_recursive_postorder_helper_##NODE_NAME(obj->right, print_val);\
    }\
    print_val(obj->val);\
    return;\
}\
bool print_recursive_postorder_##NAME(NAME* obj, void(*print_val)(TYPE)){\
    if(!obj){\
        return false;\
    }\
    print_recursive_postorder_helper_##NODE_NAME(obj->root, print_val);\
    return true;\
}




#endif