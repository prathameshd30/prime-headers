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

// #define NDEBUG
#include <assert.h>
#include "../../../include/data_structures/vector/vector.h"
#include "../../../include/algorithms/sorting/bubble_sort.h"

DEFINE_VECTOR(intVec,int)
DEFINE_BUBBLE_SORT(int)

void print_int(int a){
    printf("%d ",a);
}

bool less_than(int a, int b){
    return a<b;
}

bool swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

bool intIsEqual(int a, int b){
    return a==b;
}

int main(void){
    const uint64_t size = 10;
    intVec* intVecExample = new_intVec(10,0);
    if(!intVecExample){
        puts("Failed to make vector\n");
        return -1;
    }
    printf("Current intVecExample - ");
    print_intVec(intVecExample,print_int);
    putchar('\n');
    if(!set_at_intVec(intVecExample,0,1)){
        puts("Invalid index\n");
        return -1;
    }
    assert(intVecExample->data[0]==1);
    printf("Current intVecExample - ");
    print_intVec(intVecExample,print_int);
    putchar('\n');
    if(!set_at_intVec(intVecExample,1,2)){
        puts("Invalid index\n");
        return -1;
    }
    printf("Current intVecExample - ");
    print_intVec(intVecExample,print_int);
    putchar('\n');
    for (uint64_t i = 0; i < intVecExample->size; ++i)
    {
        if(!set_at_intVec(intVecExample,i,i+1)){
            puts("Invalid set operation\n");
            return -1;
        }
    }
    printf("Current intVecExample - ");
    print_intVec(intVecExample,print_int);
    putchar('\n');
    int element_at_index;
    if(!at_intVec(intVecExample,1,&element_at_index)){
        puts("Invalid index for querying value\n");
        return -1;
    }
    printf("Element at index 1 - %d\n",element_at_index);
    for(uint64_t i = 0; i<intVecExample->size; ++i){
        at_intVec(intVecExample,i,&element_at_index);
        printf("%d ",element_at_index);
    }
    putchar('\n');
    if(!add_at_beginning_intVec(intVecExample,0)){
        puts("Cannot reallocate space for vector");
        return -1;
    }
    printf("Current intVecExample - ");
    print_intVec(intVecExample,print_int);
    putchar('\n');
    if(!add_at_end_intVec(intVecExample,11)){
        puts("Cannot reallocate space for vector");
        return -1;
    }
    printf("Current intVecExample - ");
    print_intVec(intVecExample,print_int);
    putchar('\n');
    if(!remove_from_beginning_intVec(intVecExample,&element_at_index, NULL)){
        puts("Cannot remove element");
        return -1;
    }
    printf("Removed element - %d\n",element_at_index);
    print_intVec(intVecExample, print_int);
    putchar('\n');
    if(!remove_from_end_intVec(intVecExample,&element_at_index, NULL)){
        puts("Cannot remove element");
        return -1;
    }
    printf("Removed element - %d\n",element_at_index);
    print_intVec(intVecExample,print_int);
    putchar('\n');
    printf("Using algorithms from the library\nSorted in descending order (bubble sort) - ");
    bubble_sort_int(intVecExample->data,intVecExample->size,less_than,swap);
    print_intVec(intVecExample,print_int);
    uint64_t found_index;
    int element = 5;
    putchar('\n');
    if(linear_search_intVec(intVecExample,element,intIsEqual,&found_index)){
        printf("Found element %d at %llu\n",element,found_index);
    }
    for (int i = 0; i < 10; ++i)
    {
        if(!remove_from_beginning_intVec(intVecExample,&element, NULL)){
            printf("Vector is empty, cannot remove\n");
        }
        printf("Removed element %d from beginning\n",element);
        print_intVec(intVecExample,print_int);
        putchar('\n');
    }
    if(!remove_from_beginning_intVec(intVecExample,&element, NULL)){
            printf("Vector is empty, cannot remove\n");
        }
    
    return 0;
}