#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdbool.h>
#include <stdint.h>
#define DEFINE_BUBBLE_SORT_ARR(NAME,TYPE)\
bool bubble_sort_##NAME(TYPE* data, uint64_t size, bool (*comparator)(TYPE, TYPE), bool (*swap)(TYPE*,TYPE*)){\
    if(!data || size == 0 || !comparator || !swap){\
        return false;\
    }\
    TYPE temp;\
    for(uint64_t i = 0; i<size; ++i){\
        for(uint64_t j = 0; j<size-i-1; ++j){\
            if(comparator(data[j], data[j+1])){\
                swap(&data[j],&data[j+1]);\
            }\
        }\
    }\
    return true;\
}\
bool optimised_bubble_sort_##NAME(TYPE* data, uint64_t size, bool (*comparator)(TYPE, TYPE), bool (*swap)(TYPE*,TYPE*)){\
    if(!data || size == 0 || !comparator || !swap){\
        return false;\
    }\
    TYPE temp;\
    bool sorted;\
    for(uint64_t i = 0; i<size; ++i){\
        sorted = false;\
        for(uint64_t j = 0; j<size-i-1; ++j){\
            if(comparator(data[j],data[j+1])){\
                swap(&data[j],&data[j+1]);\
                sorted = false;\
            }\
        }\
        if(sorted){\
            return true;\
        }\
    }\
}




#endif
