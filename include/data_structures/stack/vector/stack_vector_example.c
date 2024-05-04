/**
 * @file stack_vector_example.c
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-05
 * 
 * 
 */
#include <stdio.h>
#include "stack_vector.h"

DEFINE_STACK(intStack, int)

void printInt(int a){
    printf("%d ",a);
}

int main(int argc, char const *argv[])
{
    intStack* ist = new_intStack();
    push_intStack(ist, 5);
    push_intStack(ist,6);
    print_intStack(ist, printInt);
    putc('\n',stdout);
    pop_intStack(ist);
    print_intStack(ist, printInt);
    delete_intStack(ist,NULL);
    return 0;
}
