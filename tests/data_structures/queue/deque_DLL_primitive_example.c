#include <stdio.h>
#include "../../../include/data_structures/linked_list/doubly_linked_list.h"

DEFINE_DLL_NODE(intNode, int)

void print_int(int a){
    printf("%d ",a);
}

int main(void){
    intNode* head = new_intNode(0,NULL,NULL);
    print_DLL_intNode(head,print_int);
    putchar('\n');
    insert_at_head_DLL_intNode(&head,-1);
    print_DLL_intNode(head,print_int);
    insert_at_end_DLL_intNode(head,1);
    putchar('\n');
    print_DLL_intNode(head,print_int);
}