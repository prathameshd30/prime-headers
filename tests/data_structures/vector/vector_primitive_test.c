#include <stdio.h>

//For manual valgrind testing
// #include "../../../include/data_structures/vector/vector.h"
// #include "../../../include/algorithms/sort/bubble_sort.h"

#include "vector.h"
#include "bubble_sort.h"

DEFINE_VECTOR(intVec,int)
DEFINE_BUBBLE_SORT_ARR(intArr,int)

/* To print the vector, we must pass in a function (pointer) which
prints a single instance of the type stored in vector. */
void print_int(int a){
    printf("%d ",a);
}

// Comparator for swapping when sorting the array
bool less_than(int a, int b){
    return a<b;
}

// Comparator for linear search
bool int_is_equal(int a, int b){
    return a==b;
}

int main(void){
    intVec* iv = new_intVec(0);
    if(!iv){
        puts("Failed to create int_vector");
        return -1;
    }
    if(!is_empty_intVec(iv)){
        puts("Vector with zero size is not empty");
        return -1;
    }
    if(iv->data != NULL){
        puts("Empty vector not nulled");
        return -1;
    }
    delete_intVec(iv,NULL);

    const uint64_t size = 10;
    iv = new_intVec(size);

    if(is_empty_intVec(iv)){
        puts("Non-empty vector triggers isEmpty");
        return -1;
    }

    const int element = 10;
    set_whole_intVec(iv,element);
    print_intVec(iv,print_int);
    putchar('\n');
    int return_element; //Get result of at in param for easy out of bound check
    for(uint64_t i = 0; i<iv->size; ++i){
        if(!at_intVec(iv,i,&return_element)){
            puts("Tried to at_vec out of bounds");
            return -1;
        }
        if(return_element != element){
            puts("set_at_whole wrong/incomplete");
            return -1;
        }
    }
    //Test that out of bounds is invalid
    if(at_intVec(iv,size,&return_element)){
        puts("Out of bounds being valid");
        return -1;
    }

    for(uint64_t i = 0; i<iv->size; ++i){
        if(!set_at_intVec(iv,i,i)){
            puts("set_at failing");
        }
    }
    print_intVec(iv,print_int);
    putchar('\n');

    //Test out of bounds
    if(set_at_intVec(iv,iv->size,0)){
        puts("set_at out of bounds being accepted");
    }


    return 0;
}