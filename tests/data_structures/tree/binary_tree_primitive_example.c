#include <stdio.h>
#include "../../../include/data_structures/tree/binary_tree.h"

DEFINE_BINARY_TREE(intBinTree,intNode,int)

void print_int(int a){
    printf("%d ",a);
}

void printAllTraversals(intBinTree* obj){
    printf("Preorder traversal - ");
    print_recursive_preorder_intBinTree(obj,print_int);
    putchar('\n');
    printf("Inorder traversal - ");
    print_recursive_inorder_intBinTree(obj,print_int);
    putchar('\n');
    printf("Postorder traversal - ");
    print_recursive_postorder_intBinTree(obj,print_int);
    putchar('\n');
}

int main(void){
    intBinTree* binTree = new_intBinTree(1);
    if(binTree==NULL){
        puts("Tree creation failed");
        return -1;
    }
    printAllTraversals(binTree);
    putchar('\n');
    if(!insert_at_left_intNode(binTree->root,0,NULL,NULL)){
        puts("Insertion failed");
        return -1;
    }
    printAllTraversals(binTree);
    putchar('\n');
    if(!insert_at_right_intNode(binTree->root,2,NULL,NULL)){
        puts("Insertion failed");
        return -1;
    }
    printAllTraversals(binTree);
    putchar('\n');
}