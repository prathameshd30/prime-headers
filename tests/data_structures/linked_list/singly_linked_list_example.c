#include <stdio.h>
#include "../../../include/data_structures/linked_list/singly_linked_list.h"

DEFINE_SINGLY_LINKED_LIST_NODE(intNode, int)

void printInt(int a){
    printf("%d ",a);
}

bool intIsEqual(int a, int b){
    return a==b;
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
    intNode* tempNode=NULL;
    printf("%d\n",linear_search_intNode(in,intIsEqual,1,&tempNode));
    printf("%d\n",tempNode->val);
    return 0;
}
