#include <stdio.h>
#include "../../../include/data_structures/stack/stack_SLL.h"

DEFINE_STACK_SLL(intStack,intNode, int)

void print_int(int a){
    printf("%d ",a);
}

int main(void){
    intStack* is = new_intStack();
    push_intStack(is,0);
    push_intStack(is,1);
    pop_intStack(is,NULL);
    pop_intStack(is,NULL);
    print_intStack(is,print_int);
    return 0;
}
