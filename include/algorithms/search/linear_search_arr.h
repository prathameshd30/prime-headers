#ifndef LINEAR_SEARCH
#define LINEAR_SEARCH

#include <stdbool.h>
#include <stdint.h>

#define DEFINE_LINEAR_SEARCH_ARR(NAME, TYPE)\
bool linear_search_##NAME(TYPE* arr, uint64_t arrSize, bool(*comparator)(TYPE,TYPE), TYPE ref ,uint64_t* index){\
    for (uint64_t i = 0; i < count; ++i){\
        if(comparator(ref,arr[i])){\
            *index = i;\
            return true;\
        }\
    }\
    return false;\
}

#endif