/**
 * @file singly_linked_list_example.c
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-05
 * 
 * 
 */
#include <stdio.h>
#include "../../../include/data_structures/linked_list/singly_linked_list.h"

DEFINE_SINGLY_LINKED_LIST_NODE(intNode, int)

void printInt(int a){
    printf("%d ",a);
}

int main(int argc, char const *argv[])
{
    intNode* in = new_intNode(0,NULL);
    print_SLL_intNode(in,printInt);
    putchar('\n');
    insert_after_SLL_intNode(in,1);
    print_SLL_intNode(in,printInt);
    putchar('\n');
    insert_at_end_SLL_intNode(in,2);
    print_SLL_intNode(in,printInt);
    putchar('\n');
    return 0;
}
