/**
 * @file vector_primitive_example.c
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-05
 * 
 * 
 */

#include <stdio.h>
#include "vector.h"


DEFINE_VECTOR(intVec,int);

void print_int(int a){
    printf("%d ",a);
}

int main(void){
    intVec* new_obj = new_intVec(5);
    set_at_intVec(new_obj,0,1);
    set_at_intVec(new_obj,1,2);
    set_at_intVec(new_obj,2,3);
    set_at_intVec(new_obj,3,4);
    set_at_intVec(new_obj,4,5);
    print_intVec(new_obj,print_int);
    putchar('\n');
    add_at_beginning_intVec(new_obj,0);
    print_intVec(new_obj,print_int);
    putchar('\n');
    remove_from_end_intVec(new_obj,NULL);
    print_intVec(new_obj,print_int);
    putchar('\n');
}

