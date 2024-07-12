/* This implementation of vector does not preallocate memory to save time, as I intend for this to be a simple-to-understand implementation rather than the 'best' one*/
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
NAME* new_##NAME(uint64_t size){ /*Size is set only after allocation of vector->data memory, need someone to clarify if this is advised*/ \
    NAME* new_obj = malloc(sizeof(NAME));\
    if(!new_obj){\
        return NULL;\
    }\
    if(size == 0){\
        new_obj->data = NULL;\
        new_obj->size = 0   ;\
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
NAME* construct_from_arr_##NAME(TYPE* arr, uint64_t size){\
    if(!arr){\
        return NULL;\
    }\
    NAME* new_obj = new_##NAME(size);\
    if(!new_obj){\
        return NULL;\
    }\
    if(size == 0){\
        return new_obj;\
    }\
    for(uint64_t index = 0; index < new_obj->size; ++index){\
        new_obj->data[index] = arr[index];\
    }\
    return new_obj;\
}\
bool is_empty_##NAME(NAME* obj){\
    if(!obj){\
        return false;\
    }\
    if(obj->size == 0 || obj->data == NULL){\
        return true;\
    }\
    return false;\
}\
bool at_##NAME(NAME* obj, uint64_t index, TYPE* val){\
    if(!obj || !val){\
        return false;\
    }\
    if(index > obj->size - 1){\
        val = NULL;\
        return false;\
    }\
    *val = obj->data[index];\
    return true;\
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
bool set_whole_##NAME(NAME* obj, TYPE val){\
    if(!obj || !(obj->data) || (obj->size == 0)){\
        return false;\
    }\
    for(uint64_t index = 0; index < obj->size; ++index){\
        obj->data[index] = val;\
    }\
    return true;\
}\
bool add_at_end_##NAME(NAME* obj, TYPE val){\
    if(!obj){\
        return false;\
    }\
    TYPE* temp = realloc(obj->data, (obj->size + 1)* sizeof(TYPE));\
    if(!temp){\
        return false;\
    }\
    obj->data = temp;\
    ++obj->size;\
    obj->data[obj->size - 1] = val;\
    return true;\
}\
bool add_at_beginning_##NAME(NAME* obj, TYPE val){\
    if(!obj){\
        return false;\
    }\
    TYPE* temp = realloc(obj->data, (obj->size + 1) * sizeof(TYPE));\
    if(!temp){\
        return false;\
    }\
    obj->data = temp;\
    ++obj->size;\
    for(uint64_t i = obj->size - 1; i>0; --i){\
        obj->data[i] = obj->data[i-1];\
    }\
    obj->data[0] = val;\
    return true;\
}\
bool remove_from_beginning_##NAME(NAME* obj, TYPE* val, bool (*delete_element)(TYPE)){\
    if(!obj || !obj->data || obj->size == 0){\
        return false;\
    }\
    if(val){\
        *val = obj->data[0];\
    }\
    else if(delete_element){\
        delete_element(obj->data[0]);\
    }\
    for(uint64_t i = 1; i<obj->size; ++i){\
        obj->data[i-1] = obj->data[i];\
    }\
    TYPE* temp = realloc(obj->data, (obj->size-1) * sizeof(TYPE));\
    if(!temp){\
        return false;\
    }\
    obj->data = temp;\
    --(obj->size);\
    return true;\
}\
bool remove_from_end_##NAME(NAME* obj, TYPE* val, bool (*delete_type)(TYPE)){\
    if(!obj || !obj->data || obj->size == 0){\
        return false;\
    }\
    if(val){\
        *val = obj->data[obj->size-1];\
    }\
    else if(delete_type){\
        delete_type(obj->data[obj->size-1]);\
    }\
    TYPE* temp = realloc(obj->data, (obj->size-1)*sizeof(TYPE));\
    if(!temp){\
        return false;\
    }\
    obj->data = temp;\
    --(obj->size);\
    return true;\
}\
void print_##NAME(NAME* obj, void (*print_element)(TYPE)){\
    if(!obj || !print_element || !(obj->data)){\
        return;\
    }\
    for(uint64_t i = 0; i < obj->size; ++i){\
        print_element(obj->data[i]);\
    }\
}\
bool linear_search_##NAME(NAME* obj, TYPE ref ,bool (*comparator)(TYPE, TYPE), uint64_t *index){\
    if(!obj || !obj->data || obj->size == 0 || !(comparator)){\
        return false;\
    }\
    for(uint64_t i = 0; i<obj->size; ++i){\
        if(comparator(obj->data[i], ref)){\
            *index = i;\
            return true;\
        }\
    }\
    return false;\
}\
bool delete_##NAME(NAME* obj, bool (*delete_type)(TYPE)){\
    if(!obj){\
        return false;\
    }\
    if(obj->data){\
        if(delete_type){\
            for(uint64_t i = 0; i<obj->size; ++i){\
                delete_type(obj->data[i]);\
            }\
        }\
        free(obj->data);\
    }\
    free(obj);\
    return true;\
}\
bool clear_##NAME(NAME* obj, bool (*delete_type)(TYPE), TYPE val){\
    if(!obj){\
        return false;\
    }\
    if(obj->data && delete_type){\
        for(uint64_t i = 0; i<obj->size; ++i){\
            delete_type(obj->data[i]);\
        }\
        free(obj->data);\
    }\
    obj->data = NULL;\
    obj->size = 0;\
    return true;\
}

#endif