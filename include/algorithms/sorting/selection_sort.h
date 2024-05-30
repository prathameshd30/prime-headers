/**
 * @file selection_sort.h
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-05
 * 
 * 
 */

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <stdint.h>
#include <stdbool.h>

#define DEFINE_SELECTION_SORT(TYPE)\
bool selection_sort_##TYPE(TYPE* data, uint64_t size, bool (*comparator)(TYPE, TYPE), bool (*swap)(TYPE*, TYPE*)){\
    if(!data || size == 0 || !comparator || !swap){\
        return false;\
    }\
    uint64_t key_index;\
    for (uint64_t i = 0; i < size; ++i){\
        key_index = i;\
        for(uint64_t j = i+1; j<size; ++j){\
            if(comparator(data[key_index],data[j])){\
                key_index = j;\
            }\
        }\
        if(key_index != i){\
            swap(&data[key_index],&data[i]);\
        }\
    }\
    return true;\
}

#endif