/**
 * @file vector.h
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-04
 * 
 * 
 */
#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

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
    if(size == 0){\
        new_obj->data = NULL;\
        new_obj->size = 0;\
        return new_obj;\
    }\
    new_obj->data = calloc(size,sizeof(TYPE));\
    if(!(new_obj->data)){\
        free(new_obj);\
        return NULL;\
    }\
    new_obj->size = size;\
    return new_obj;\
}\
bool at_##NAME(NAME* obj, uint64_t index, TYPE* val){\
    if(!obj){\
        return false;\
    }\
    if(index > obj->size - 1){\
        *val = NULL;\
        return false;\
    }\
    return obj->data[index];\
}\
bool set_at_##NAME(NAME* obj, uint64_t index, TYPE val){\
    if(!obj){\
        return false;\
    }\
    if(index > obj->size -1){\
        return false;\
    }\
    obj->data[index] = val;\
    return true;\
}\




#endif