#include <stdio.h>

//For manual valgrind testing
// #include "../../../include/data_structures/vector/vector.h"
// #include "../../../include/algorithms/sort/bubble_sort.h"

#include "vector.h"
#include "bubble_sort.h"

#define ARRAY_SIZE 10

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
    // Testing of 0 sized constructor
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
    delete_intVec(&iv,NULL);
    if(iv!=NULL){
        puts("Deleted integer vector still points to memory");
        return -1;
    }

    // Testing of +ve sized constructor
    const uint64_t size = 10;
    iv = new_intVec(size);
    if(iv->size != size){
        puts("Vector size incorrectly set");
        return -1;
    }
    if(iv->data == NULL){
        puts("Vector data is NULL even though size is not 0");
        return -1;
    }
    delete_intVec(&iv, NULL);
    if(iv!=NULL){
        puts("Deleted vector of +ve size is not NULL");
        return -1;
    }
    
    // Test at uint64_t max (IMPRACTICAL, Roughly 73700 Petabytes of RAM needed)
    // iv = new_intVec(UINT64_MAX);
    // if(!iv){
    //     puts("Vector not created cleanly at size UINT64_MAX");
    //     return -1;
    // }
    // if(iv->size!=UINT64_MAX){
    //     puts("Incorrect vector size set at UINT64_MAX");
    //     return -1;
    // }
    // if(iv->data==NULL){
    //     puts("Vector data is NULL at size UINT64_MAX");
    //     return -1;
    // }
    // delete_intVec(&iv,NULL);
    // if(iv!=NULL){
    //     puts("Vector is not null after being freed at UINT64_MAX");
    //     return -1;
    // }

    /* Negative size testing is not possible as parameter passed to the constructor
    is in itself an unsigned quantity. Hence, a negative number would just be
    converted to a (rather large) positive integer */

    /* It was done this way to maximise the largest size supported by the vector,
    though, in doing so, it transfers a burden onto the programmer to check
    whatever size is passed in to the constructor, is +ve*/

    
    int arr[ARRAY_SIZE] = {0};
    for(uint64_t i = 0; i<sizeof(arr)/sizeof(arr[0]); ++i){
        arr[i] = i;
    }
    iv = construct_from_arr_intVec(arr,sizeof(arr)/sizeof(arr[0]));
    if(iv->size != sizeof(arr)/sizeof(arr[0])){
        puts("Vector size incorrectly set");
        return -1;
    }
    print_intVec(iv,print_int);
    putchar('\n');
    delete_intVec(&iv, NULL);
    if(iv!=NULL){
        puts("Deleted vector not NULL");
        return -1;
    }
    // Construction from array tested
    

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

    if(!set_whole_intVec(iv,0)){
        puts("set_at_whole failed with non-empty vector");
        return -1;
    }
    print_intVec(iv,print_int);
    putchar('\n');

    if(!add_at_end_intVec(iv,1)){
        puts("add_at_end failed");
        return -1;
    }

    if(!add_at_beginning_intVec(iv,-1)){
        puts("add_at_beginning failed");
        return -1;
    }
    
    // More tests required!

    delete_intVec(&iv,NULL);
    return 0;
}