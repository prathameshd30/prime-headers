/**
 * @file queue_vector.h
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-06-01
 * 
 * 
 */

#ifndef QUEUE_VECTOR_H
#define QUEUE_VECTOR_H
#include "../vector/vector.h"

#define DEFINE_QUEUE_VECTOR(NAME, VEC_NAME, TYPE)\
DEFINE_VECTOR(VEC_NAME,TYPE)\
struct NAME{\
    VEC_NAME* vec;\
};\
typedef struct NAME NAME;\
NAME* new_##NAME(TYPE val){\
    NAME* obj = malloc(sizeof(NAME));\
    obj->vec = new_##VEC_NAME(0,val);\
    return obj;\
}\
bool enqueue_##NAME(NAME* obj, TYPE val){\
    return add_at_end_##VEC_NAME(obj->vec,val);\
}\
bool dequeue_##NAME(NAME* obj, TYPE* val){\
    return remove_from_beginning_##VEC_NAME(obj->vec, val, NULL);\
}

#endif