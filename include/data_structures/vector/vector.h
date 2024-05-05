/**
 * @file vector.h
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-04
 * 
 * This implementation of vector does not preallocate memory to save time, as I intend for this to be a simple-to-understand implementation rather than the 'best' one
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
        val = NULL;\
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
bool add_at_end_##NAME(NAME* obj, TYPE val){\
    if(!obj){\
        return false;\
    }\
    obj->data = realloc(obj->data, (obj->size +1)* sizeof(TYPE));\
    if(!obj->data){\
        return false;\
    }\
    ++obj->size;\
    obj->data[obj->size - 1] = val;\
    return true;\
}\
bool add_at_beginning_##NAME(NAME* obj, TYPE val){\
    if(!obj){\
        return false;\
    }\
    obj->data = realloc(obj->data, (obj->size + 1) * sizeof(TYPE));\
    if(!obj->data){\
        return false;\
    }\
    ++obj->size;\
    for(uint64_t i = obj->size - 1; i>0; --i){\
        obj->data[i] = obj->data[i-1];\
    }\
    obj->data[0] = val;\
    return true;\
}\
bool remove_from_beginning_##NAME(NAME* obj, TYPE* val){\
    if(!obj){\
        return false;\
    }\
    if(val){\
        *val = obj->data[0];\
    }\
    for(uint64_t i = 1; i<obj->size; ++i){\
        obj->data[i-1] = obj->data[i];\
    }\
    obj->data = realloc(obj->data, (obj->size-1) * sizeof(TYPE));\
    if(!obj->data){\
        return false;\
    }\
    return true;\
}\
bool remove_from_end_##NAME(NAME* obj, TYPE* val){\
    if(!obj){\
        return false;\
    }\
    if(val){\
        *val = obj->data[obj->size-1];\
    }\
    --obj->size;\
    obj->data = realloc(obj->data, (obj->size-1)*sizeof(TYPE));\
    if(!obj->data){\
        return false;\
    }\
    return true;\
}\
void print_##NAME(NAME* obj, void (*print_##TYPE)(TYPE)){\
    for(uint64_t i = 0; i < obj->size; ++i){\
        print_##TYPE(obj->data[i]);\
    }\
}\



#endif