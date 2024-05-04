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

#define DEFINE_STACK(NAME, TYPE)                                                                                                                                                                                  \
    typedef struct NAME NAME;                                                                                                                                                                                     \
    struct NAME                                                                                                                                                                                                   \
    {                                                                                                                                                                                                             \
        int64_t top;                                                                                                                                                                                              \
        TYPE *data;                                                                                                                                                                                               \
    };                                                                                                                                                                                                            \
    NAME *new_##NAME(void);                                                                                                                                                                                       \
    bool isEmpty_##NAME(const NAME *const);                                                                                                                                                                       \
    bool push_##NAME(NAME *, TYPE);                                                                                                                                                                               \
    bool pop_##NAME(NAME *);                                                                                                                                                                                      \
    bool top_##NAME(const NAME *const, TYPE *);                                                                                                                                                                   \
    bool delete_##NAME(NAME *, bool (*delete_##TYPE)(TYPE*)); /*Should there be a delete stack operation which will be provided a deleteType function?                                                          */ \
    void print_##NAME(const NAME *const, void (*print_##TYPE)(TYPE));                                                                                                                                             \
    NAME *new_##NAME(void)                                                                                                                                                                                        \
    {                                                                                                                                                                                                             \
        NAME *new_obj = malloc(sizeof(NAME));                                                                                                                                                                     \
        if (!new_obj)                                                                                                                                                                                             \
        {                                                                                                                                                                                                         \
            return NULL;                                                                                                                                                                                          \
        }                                                                                                                                                                                                         \
        new_obj->top = -1;                                                                                                                                                                                      \
        new_obj->data = NULL;                                                                                                                                                                                     \
        return new_obj;                                                                                                                                                                                           \
    }                                                                                                                                                                                                             \
    bool isEmpty_##NAME(const NAME *const obj_pointer)                                                                                                                                                            \
    {                                                                                                                                                                                                             \
        if (!obj_pointer)                                                                                                                                                                                         \
        {                                                                                                                                                                                                         \
            return true; /*Check whether this should return true or false */                                                                                                                                      \
        }                                                                                                                                                                                                         \
        return (obj_pointer->top == -1);                                                                                                                                                                          \
    }                                                                                                                                                                                                             \
    bool push_##NAME(NAME *obj_pointer, TYPE element)                                                                                                                                                             \
    {                                                                                                                                                                                                             \
        if (!obj_pointer)                                                                                                                                                                                         \
        {                                                                                                                                                                                                         \
            return false;                                                                                                                                                                                         \
        }                                                                                                                                                                                                         \
        ++(obj_pointer->top);                                                                                                                                                                                     \
        obj_pointer->data = realloc(obj_pointer->data, (obj_pointer->top + 1) * sizeof(TYPE));                                                                                                                    \
        if (!(obj_pointer->data))                                                                                                                                                                                 \
        {                                                                                                                                                                                                         \
            return false;                                                                                                                                                                                         \
        };                                                                                                                                                                                                        \
        obj_pointer->data[obj_pointer->top] = element;                                                                                                                                                            \
        return true;                                                                                                                                                                                              \
    }                                                                                                                                                                                                             \
    bool pop_##NAME(NAME *obj_pointer)                                                                                                                                                                            \
    {                                                                                                                                                                                                             \
        if (!obj_pointer)                                                                                                                                                                                         \
        {                                                                                                                                                                                                         \
            return false;                                                                                                                                                                                         \
        }                                                                                                                                                                                                         \
        if (isEmpty_##NAME(obj_pointer))                                                                                                                                                                          \
        {                                                                                                                                                                                                         \
            return false;                                                                                                                                                                                         \
        }                                                                                                                                                                                                         \
        --(obj_pointer->top);                                                                                                                                                                                     \
        if (obj_pointer->top == -1)                                                                                                                                                                               \
        {                                                                                                                                                                                                         \
            obj_pointer->data = NULL;                                                                                                                                                                             \
        }                                                                                                                                                                                                         \
        else                                                                                                                                                                                                      \
        {                                                                                                                                                                                                         \
            obj_pointer->data = realloc(obj_pointer->data, (obj_pointer->top + 1) * sizeof(TYPE));                                                                                                                \
        }                                                                                                                                                                                                         \
        return true;                                                                                                                                                                                              \
    }                                                                                                                                                                                                             \
    bool top_##NAME(const NAME *const obj_pointer, TYPE *result)                                                                                                                                                  \
    {                                                                                                                                                                                                             \
        if (!obj_pointer)                                                                                                                                                                                         \
        {                                                                                                                                                                                                         \
            return false;                                                                                                                                                                                         \
        }                                                                                                                                                                                                         \
        if (isEmpty_##NAME(obj_pointer))                                                                                                                                                                          \
        {                                                                                                                                                                                                         \
            return false;                                                                                                                                                                                         \
        }                                                                                                                                                                                                         \
        *result = obj_pointer->data[obj_pointer->top];                                                                                                                                                            \
        return true;                                                                                                                                                                                              \
    }                                                                                                                                                                                                             \
    bool delete_##NAME(NAME *obj_pointer, bool (*delete_##TYPE)(TYPE))                                                                                                                                            \
    {                                                                                                                                                                                                             \
        if (!obj_pointer)                                                                                                                                                                                         \
        {                                                                                                                                                                                                         \
            return false;                                                                                                                                                                                         \
        }                                                                                                                                                                                                         \
        if (delete_##TYPE)                                                                                                                                                                                        \
        {                                                                                                                                                                                                         \
            for (int64_t i = 0; i < obj_pointer->top + 1; ++i)                                                                                                                                                    \
            {                                                                                                                                                                                                     \
                delete_##TYPE(obj_pointer->data[i]);                                                                                                                                                              \
            }                                                                                                                                                                                                     \
        }                                                                                                                                                                                                         \
        free(obj_pointer);                                                                                                                                                                                        \
        return true;                                                                                                                                                                                              \
    }                                                                                                                                                                                                             \
    void print_##NAME(const NAME *const obj_pointer, void (*print_##TYPE)(TYPE))                                                                                                                                  \
    {                                                                                                                                                                                                             \
        if (!obj_pointer)                                                                                                                                                                                         \
        {                                                                                                                                                                                                         \
            return;                                                                                                                                                                                               \
        }                                                                                                                                                                                                         \
        for (int64_t i = obj_pointer->top; i >= 0; --i)                                                                                                                                                           \
        {                                                                                                                                                                                                         \
            print_##TYPE(obj_pointer->data[i]);                                                                                                                                                                   \
        }                                                                                                                                                                                                         \
    }
#endif