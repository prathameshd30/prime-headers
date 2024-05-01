#include <stdio.h>
#include "insertion_sort.h"

DEFINE_INSERTION_SORT(int)

#define SIZE 10

bool greater_than(int a, int b){
    return a>b;
}

bool swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

int main(void){
    int a[SIZE] = {0,3,5,4,1,2,8,6,7,9};
    insertion_sort_int(a,sizeof(a)/sizeof(a[0]),greater_than,swap);
    for(int i = 0; i<sizeof(a)/sizeof(a[0]);++i){
        printf("%d ",a[i]);
    }
}