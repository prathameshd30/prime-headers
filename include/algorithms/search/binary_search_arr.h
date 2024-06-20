#ifndef BINARY_SEARCH_ARR_H
#define BINARY_SEARCH_ARR_H

#include <stdint.h>

#define DEFINE_BINARY_SEARCH_ARR(NAME, TYPE)\
TYPE* recursive_binary_helper_##NAME(TYPE* arr, uint64_t low, uint64_t high, TYPE val, int16_t (*comparator)(TYPE, TYPE)){\
    if(high >= low){\
        uint64_t mid = (low+high)/2;\
        int16_t res = comparator(val ,arr[mid]);\
        if(res == 0){\
            return &(arr[mid]);\
        }\
        else if(res < 0){\
            return recursive_binary_helper_##NAME(arr, low, mid, val, comparator);\
        }\
        else if(res > 0){\
            return recursive_binary_helper_##NAME(arr, mid+1, high, val, comparator);\
        }\
    }\
    return NULL;\
}\
TYPE* recursive_binary_search_##NAME(TYPE* arr, size_t size, TYPE val ,int16_t (*comparator)(TYPE,TYPE)){\
    uint64_t low = 0;\
    uint64_t high = size - 1;\
    return recursive_binary_helper_##NAME(arr, low, high, val, comparator);\
}\



#endif