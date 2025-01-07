/**
 * TO DO
 * Delete Node (All 3 Cases, Leaf Node, 1 Child, 2 Children)
 */
#ifndef BST_H
#define BST_H

#include <stdint.h>
#include "binary_tree.h"

#define DEFINE_BINARY_SEARCH_TREE(TREE_NAME, NODE_NAME,TYPE)\
DEFINE_BINARY_TREE(TREE_NAME,NODE_NAME, TYPE)\
bool recursive_insert_BST_helper_##TREE_NAME(NODE_NAME* root, TYPE val, int16_t (*comparator)(TYPE, TYPE)){\
    if(!root){\
        return false;\
    }\
    int16_t result = comparator(val, root->val);\
    if(result == 0){\
        return false;\
    }\
    else if(result > 0){\
        if(root->right){\
            recursive_insert_BST_helper_##TREE_NAME(root->right,val, comparator);\
        }\
        else{\
            return insert_at_right_##NODE_NAME(root,val,NULL,NULL);\
        }\
    }\
    else if(result < 0){\
        if(root->left){\
            recursive_insert_BST_helper_##TREE_NAME(root->left,val, comparator);\
        }\
        else{\
            insert_at_left_##NODE_NAME(root,val,NULL,NULL);\
        }\
    }\
    return root;\
}\
bool recursive_insert_BST_##TREE_NAME(TREE_NAME* tree, TYPE val, int16_t (*comparator)(TYPE, TYPE)){\
    if(!(tree->root)){\
        return false;\
    }\
    if(recursive_insert_BST_helper_##TREE_NAME(tree->root,val,comparator)){\
        return true;\
    }\
    return false;\
}\
NODE_NAME* recursive_search_BST_helper_##TREE_NAME(NODE_NAME* root, TYPE val, int16_t (*comparator)(TYPE,TYPE)){\
    if(!root){\
        return NULL;\
    }\
    int16_t result = comparator(val, root->val);\
    if(result == 0){\
        return root;\
    }\
    else if(result > 0){\
        return recursive_search_BST_helper_##TREE_NAME(root->right, val, comparator);\
    }\
    else if(result < 0){\
        return recursive_search_BST_helper_##TREE_NAME(root->left, val, comparator);\
    }\
    return NULL; /*Should be impossible to reach*/\
}\
NODE_NAME* recursive_search_BST_##TREE_NAME(TREE_NAME* tree, TYPE val, int16_t(*comparator)(TYPE, TYPE)){\
    return recursive_search_BST_helper_##TREE_NAME(tree->root,val,comparator);\
}

#endif