/**
 * @file insertion_sort.h
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-05
 * 
 * 
 */
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <stdint.h>
#include <stdbool.h>

#define DEFINE_INSERTION_SORT(TYPE)\
bool insertion_sort_##TYPE(TYPE* data, int64_t size, bool (*comparator)(TYPE, TYPE), bool (*swap)(TYPE*, TYPE*)){\
    if(!data || size == 0 || !comparator || !swap){\
        return false;\
    }\
    int64_t j;\
    TYPE key;\
    for(int64_t i = 1; i<size; ++i){\
        key = data[i];\
        j = i-1;\
        while(comparator(key,data[j]) && j >= 0){\
            swap(&data[j+1],&data[j]);\
            --j;\
        }\
        data[j+1] = key;\
    }\
    return true;\
}

#endif