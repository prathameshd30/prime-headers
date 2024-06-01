/**
 * @file stack_vector.h
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-05
 *
 * 
 */
#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../vector/vector.h"

#define DEFINE_STACK_VECTOR(NAME, VEC_NAME,TYPE)\
DEFINE_VECTOR(VEC_NAME,TYPE)\
typedef struct NAME NAME;\
struct NAME{\
    VEC_NAME* vec;\
    uint64_t top;\
    bool isEmpty;\
};\
NAME* new_##NAME(TYPE val){\
    NAME* new_obj = malloc(sizeof(NAME));\
    if(!new_obj){\
        return NULL;\
    }\
    new_obj->vec = new_##VEC_NAME(0,val);\
    if(!new_obj->vec){\
        free(new_obj);\
        return NULL;\
    }\
    new_obj->top = 0;\
    new_obj->isEmpty = true;\
    return new_obj;\
}\
bool isEmpty_##NAME(NAME* obj){\
    if(!obj || !obj->vec){\
        return false;\
    }\
    else if(obj->isEmpty|| !obj->vec->data || obj->vec->size == 0){\
        return true;\
    }\
    return false;\
}\
bool push_##NAME(NAME* obj, TYPE val){\
    if(!obj || !obj->vec){\
        return false;\
    }\
    if(!add_at_end_##VEC_NAME(obj->vec,val)){\
        return false;\
    }\
    else{\
        if(isEmpty_##NAME(obj)){\
            obj->isEmpty = false;\
        }\
        obj->top = obj->vec->size - 1;\
        return true;\
    }\
}\
bool top_##NAME(NAME* obj, TYPE* return_param){\
    if(!obj || !obj->vec){\
        return false;\
    }\
    if(isEmpty_##NAME(obj)){\
        return false;\
    }\
    *return_param = obj->vec->data[obj->top];\
    return true;\
}\
bool pop_##NAME(NAME* obj, bool (*delete_element)(TYPE)){\
    if(!obj || !obj->vec){\
        return false;\
    }\
    if(isEmpty_##NAME(obj)){\
        return false;\
    }\
    if(!remove_from_end_##VEC_NAME(obj->vec,NULL, delete_element)){\
        return false;\
    }\
    else{\
        return true;\
    }\
}\
bool delete_##NAME(NAME* obj, bool (*delete_element)(TYPE)){\
    if(!obj || !obj->vec){\
        return false;\
    }\
    if(delete_element){\
        delete_##VEC_NAME(obj->vec,delete_element);\
    }\
    free(obj);\
    return true;\
}\
void print_##NAME(NAME* obj, void (*print_type)(TYPE)){\
    if(isEmpty_##NAME(obj)){\
        return;\
    }\
    for(uint64_t i = obj->top; ; --i){\
        print_type(obj->vec->data[i]);\
        if(i==0){\
            return;\
        }\
    }\
}


#endif