#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdint.h>

#define DEFINE_VECTOR(NAME, TYPE)\
typedef struct NAME NAME;\
struct NAME{\
    TYPE* data;\
    uint64_t size;\
};\
NAME* new_##NAME(uint64_t size){\
    NAME* new_obj = malloc(sizeof(NAME));\
    if(!new_obj){\
        return NULL;\
    }\
    new_obj->data = calloc(size,sizeof(TYPE));\
    if(!(new_obj->data)){\
        free(new_obj);\
        return NULL;\
    }\
    return new_obj;\
}\



#endif