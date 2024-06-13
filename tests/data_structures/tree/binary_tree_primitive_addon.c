#include <stdio.h>

#include "../../../include/data_structures/tree/binary_tree.h"
#include "../../../include/data_structures/tree/binary_tree_addon.h"

DEFINE_BINARY_TREE_ALGOS(intBinTree, intNode, int, intVec, intStack, intStackVec)

void print_int(int a){
    printf("%d ",a);
}

void print_all_traversals(intBinTree* obj){
    intVec* vec;
    vec = recursive_preorder_vec_intBinTree(obj);
    printf("Preorder traversal - ");print_intVec(vec,print_int);
    putchar('\n');
    delete_intVec(vec,NULL);
    vec = recursive_inorder_vec_intBinTree(obj);
    printf("Inorder traversal - ");print_intVec(vec,print_int);
    putchar('\n');
    delete_intVec(vec,NULL);
    vec = recursive_postorder_vec_intBinTree(obj);
    printf("Postorder traversal - ");print_intVec(vec,print_int);
    putchar('\n');
    delete_intVec(vec,NULL);
}

int main(void){
    intBinTree* binTree = new_intBinTree(0);
    if(binTree==NULL){
        puts("Tree creation failed");
        return -1;
    }
    print_all_traversals(binTree);
    putchar('\n');
    if(!insert_at_left_intNode(binTree->root,1,NULL,NULL)){
        puts("Insertion failed");
        return -1;
    }
    print_all_traversals(binTree);
    putchar('\n');
    if(!insert_at_right_intNode(binTree->root,2,NULL,NULL)){
        puts("Insertion failed");
        return -1;
    }
    print_all_traversals(binTree);
    putchar('\n');
    printf("Stack preorder - ");print_preorder_intBinTree(binTree,print_int,NULL);putchar('\n');
    printf("Stack inorder - ");print_inorder_intBinTree(binTree,print_int,NULL);putchar('\n');
}