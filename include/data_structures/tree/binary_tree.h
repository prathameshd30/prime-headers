#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

#define DEFINE_BINARY_TREE(NODE, TYPE)\
struct NAME{\
    TYPE val;\
    struct NAME* left;\
    struct NAME* right;\
};\
typedef struct NAME NAME;\
NAME* new_##NAME(TYPE val, NAME* left, NAME* right){\
    NAME* obj = malloc(sizeof(NAME));\
    if(!obj){\
        return NULL;\
    }\
    obj->val = val;\
    obj->left = left;\
    obj->right = right;\
    return obj;\
}\
bool traverse_left_##NAME(NAME* root, NAME** leftNode){\
    if(!root){\
        return false;\
    }\
    else{\
        *leftNode = root->left;\
    }\
}\


#endif