#include <stdio.h>
#include "singly_linked_list.h"

DEFINE_SINGLY_LINKED_LIST_NODE(intNode, int)

void printInt(int a){
    printf("%d ",a);
}

int main(int argc, char const *argv[])
{
    intNode* in = new_intNode(0,NULL);
    print_SLL_intNode(in,printInt);
    putchar('\n');
    insert_after_intNode(in,1);
    print_SLL_intNode(in,printInt);
    putchar('\n');
    insert_at_head_intNode(&in,-1);
    insert_at_end_intNode(in,2);
    print_SLL_intNode(in,printInt);
    putchar('\n');
    return 0;
}
