#include <stdio.h>

//For manual valgrind testing
// #include "../../../include/data_structures/vector/vector.h"
// #include "../../../include/algorithms/sort/bubble_sort.h"
// #include "../../../util/testing_macro.h"

#include "vector.h"
#include "bubble_sort.h"
#include "testing_macro.h"

#define ARRAY_SIZE 10 // Is not a const global variable due to it being used for vanilla array size

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
    test(iv!=NULL,"Vector could not be created."); //Written !=NULL for readability
    test(is_empty_intVec(iv),"Zero sized vector is not empty.");
    test(iv->data == NULL, "Empty vector data not NULLed.");
    delete_intVec(&iv,NULL);
    test(iv==NULL, "Deleted integer vector still points to memory.");

    // Testing of +ve sized constructor
    const uint64_t size = 10;
    iv = new_intVec(size);
    test(iv->size == size, "Vector size incorrectly set.");
    test(iv->data != NULL, "Integer vector data is NULLed.");
    delete_intVec(&iv, NULL);
    test(iv==NULL,"Deleted integer vector still points to memory")

    /*Negative size parameter not possible due to use of uint64, transfers
    responsibility of checking size to the programmer */
    
    // Construct from raw array.
    int arr[ARRAY_SIZE] = {0};
    for(uint64_t i = 0; i<sizeof(arr)/sizeof(arr[0]); ++i){
        arr[i] = i;
    }
    iv = construct_from_arr_intVec(arr,sizeof(arr)/sizeof(arr[0]));
    test(iv->size == sizeof(arr)/sizeof(arr[0]), "Size of vector object incorrectly set.");
    print_intVec(iv,print_int);
    putchar('\n');
    delete_intVec(&iv, NULL);
    test(iv==NULL, "Deleted integer vector still points to memory.");
    
    // Test construction from array when NULL ptr
    int* test_array = NULL;
    iv = construct_from_arr_intVec(test_array,ARRAY_SIZE);
    test(iv==NULL, "Construct vector from array returns non NULL when NULL array.")

    // Test is_empty with size and set_whole
    iv = new_intVec(size);
    test(!is_empty_intVec(iv), "Non-empty vector triggers is empty.")

    //Test set_whole and at_vec
    const int element = 10;
    set_whole_intVec(iv,element);
    int got_element;
    print_intVec(iv,print_int);
    putchar('\n');
    for (uint64_t i = 0; i < iv->size; ++i)
    {
        if(at_intVec(iv,i,&got_element)){
            test(got_element==element,"Set whole vector not setting to element correctly.");
        }
        else{
            test(false,"at_vec failing")
        }
    }

    //Test that access at out of bounds is invalid
    test(!at_intVec(iv,size,&got_element),"Out of bounds is valid.")
    for(uint64_t i = 0; i<iv->size; ++i){
        test(set_at_intVec(iv,i,i),"set_at failing")
        test(at_intVec(iv,i,&got_element) && got_element == iv->data[i], "at_failing or wrong value")
    }
    print_intVec(iv,print_int);
    putchar('\n');


    //Test set at out of bounds
    test(!set_at_intVec(iv,iv->size,0),"set_at out of bounds accepted")

    //Test set whole
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