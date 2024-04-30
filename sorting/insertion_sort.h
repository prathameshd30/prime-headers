#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <stdint.h>
#include <stdbool.h>

#define DEFINE_INSERTION_SORT(TYPE)\
bool insertion_sort_##TYPE(TYPE* data, int64_t size, bool (*comparator)(TYPE, TYPE)){\
    int64_t j;\
    TYPE key;\
    for(int64_t i = 1; i<size; ++i){\
        key = data[i];\
        j = i-1;\
        while(comparator(key,data[j]) && j >= 0){\
            data[j+1] = data[j];\
            --j;\
        }\
        data[j+1] = key;\
    }\
    return true;\
}

#endif