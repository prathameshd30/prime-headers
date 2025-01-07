#include <stdio.h>

#include "../../../include/algorithms/searching/binary_search_arr.h"
#include "../../../include/algorithms/sorting/bubble_sort.h"
DEFINE_BUBBLE_SORT_ARR(intArr,int)

DEFINE_BINARY_SEARCH_ARR(intArr,int)

bool intGreater(int a, int b){
    return a>b;
}

bool swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

int16_t binInt(int a, int b){
    if(a==b){
        return 0;
    }
    else if(a < b){
        return -1;
    }
    return 1;
}

int main(void){
    int arr[] = {0,2,5,4,1};
    bubble_sort_int(arr,sizeof(arr)/sizeof(arr[0]),intGreater,swap);
    for(int i = 0; i<sizeof(arr)/sizeof(arr[0]); ++i){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
    int* res = recursive_binary_search_intArr(arr, sizeof(arr)/sizeof(arr[0]),1,binInt);
    if(res){
        printf("%d\n",*res);
    }
    
}