#include <stdio.h>
#include "bubble_sort.h"

DEFINE_BUBBLE_SORT(int);

#define SIZE 10

bool int_greater_than(int a, int b){
    return (a>b);
}

bool int_swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

int main(void){
    int a[SIZE] = {0,1,3,4,5,2,9,8,6,7};
    bubble_sort_int(a,sizeof(a)/sizeof(a[0]),int_greater_than,int_swap);
    for(int i = 0; i<sizeof(a)/sizeof(a[0]);++i){
        printf("%d ",a[i]);
    }
}