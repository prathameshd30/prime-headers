#include <stdio.h>
#include "../../../include/data_structures/tree/binary_search_tree.h"

DEFINE_BINARY_SEARCH_TREE(intBST, intBSTNode, int)

void print_int(int a){
    printf("%d ",a);
}

int16_t comparator(int a, int b){
    return a-b;
}

int main(void){
    intBST* bst = new_intBST(0);
    print_recursive_inorder_intBST(bst,print_int);
    putchar('\n');
    recursive_insert_BST_intBST(bst,-1,comparator);
    print_recursive_inorder_intBST(bst,print_int);
    putchar('\n');
    recursive_insert_BST_intBST(bst,1,comparator);
    print_recursive_inorder_intBST(bst,print_int);
    putchar('\n');
}