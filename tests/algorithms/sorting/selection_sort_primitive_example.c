/**
 * @file selection_sort_primitive_example.c
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-05
 * 
 * 
 */
#include <stdio.h>
#include "../../../include/algorithms/sorting/selection_sort.h"

DEFINE_SELECTION_SORT(int)

#define SIZE 10

bool greater_than(int a, int b){
    return a>b;
}

bool swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

int main(void){
    int a[SIZE] = {1,2,4,7,9,8,6,5,3,0};
    selection_sort_int(a,sizeof(a)/sizeof(a[0]),greater_than,swap);
    for(int i = 0; i<sizeof(a)/sizeof(a[0]);++i){
        printf("%d ",a[i]);
    }
}