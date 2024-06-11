#ifndef SLL_H
#define SLL_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/*Should there be insertAtIndex? No, use indexing to traverse through list and use insert_after using the pointer, as insert at index would use some integer size, and I don't like to choose*/

#define DEFINE_SINGLY_LINKED_LIST_NODE(NAME, TYPE)                                                              \
    typedef struct NAME NAME;                                                                                   \
    struct NAME                                                                                                 \
    {                                                                                                           \
        TYPE val;                                                                                               \
        NAME *next;                                                                                             \
    };                                                                                                          \
    NAME *new_##NAME(TYPE element, NAME *next)                                                                  \
    {                                                                                                           \
        NAME *new_obj = malloc(sizeof(NAME));                                                                   \
        if (!new_obj)                                                                                           \
        {                                                                                                       \
            return NULL;                                                                                        \
        }                                                                                                       \
        new_obj->val = element;                                                                                 \
        new_obj->next = next;                                                                                   \
        return new_obj;                                                                                         \
    }                                                                                                           \
    bool insert_at_head_SLL_##NAME(NAME **head, TYPE element)                                                   \
    {                                                                                                           \
        if (!head || !(*head))                                                                                  \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        NAME *new_obj = new_##NAME(element, *head);                                                             \
        if (!new_obj)                                                                                           \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        *head = new_obj;                                                                                        \
        return true;                                                                                            \
    }                                                                                                           \
    bool insert_after_SLL_##NAME(NAME *node, TYPE element)                                                      \
    {                                                                                                           \
        if (!node)                                                                                              \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        NAME *new_obj = new_##NAME(element, node->next);                                                        \
        if (!new_obj)                                                                                           \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        node->next = new_obj;                                                                                   \
        return true;                                                                                            \
    }                                                                                                           \
    bool insert_at_end_SLL_##NAME(NAME *head, TYPE element)                                                     \
    {                                                                                                           \
        if (!head)                                                                                              \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        NAME *new_obj = new_##NAME(element, NULL);                                                              \
        if (!new_obj || !head)                                                                                  \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        while (head->next)                                                                                      \
        {                                                                                                       \
            head = head->next;                                                                                  \
        }                                                                                                       \
        head->next = new_obj;                                                                                   \
        return true;                                                                                            \
    }                                                                                                           \
    void print_SLL_##NAME(const NAME *head, void (*print_node)(TYPE))                                           \
    {                                                                                                           \
        if (!head)                                                                                              \
        {                                                                                                       \
            return;                                                                                             \
        }                                                                                                       \
        while (head)                                                                                            \
        {                                                                                                       \
            print_node(head->val);                                                                              \
            head = head->next;                                                                                  \
        }                                                                                                       \
    }                                                                                                           \
    bool remove_head_SLL_##NAME(NAME **head, bool (*delete_val)(TYPE))                                          \
    {                                                                                                           \
        if (!head || !(*head))                                                                                  \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        NAME *temp = *head;                                                                                     \
        *head = (*head)->next;                                                                                  \
        if (delete_val)                                                                                         \
        {                                                                                                       \
            delete_val(temp->val);                                                                              \
        }                                                                                                       \
        free(temp);                                                                                             \
        return true;                                                                                            \
    }                                                                                                           \
    bool remove_tail_SLL_##NAME(NAME **head, bool (*delete_val)(TYPE))                                          \
    {                                                                                                           \
        if (!head || !(*head))                                                                                  \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        if ((*head)->next == NULL)                                                                              \
        {                                                                                                       \
            free(*head);                                                                                        \
            *head = NULL;                                                                                       \
            return true;                                                                                        \
        }                                                                                                       \
        NAME *temp = (*head)->next;                                                                             \
        NAME *tempPrev = *head;                                                                                 \
        while (temp->next)                                                                                      \
        {                                                                                                       \
            tempPrev = temp;                                                                                    \
            temp = temp->next;                                                                                  \
        }                                                                                                       \
        tempPrev->next = temp->next;                                                                            \
        if (delete_val)                                                                                         \
        {                                                                                                       \
            delete_val(temp->val);                                                                              \
        }                                                                                                       \
        free(temp);                                                                                             \
        return true;                                                                                            \
    }                                                                                                           \
    bool remove_value_SLL_##NAME(NAME **head, TYPE val, bool (*delete_val)(TYPE))                               \
    {                                                                                                           \
        if (!head || !(*head))                                                                                  \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        if ((*head)->val == val)                                                                                \
        {                                                                                                       \
            NAME *temp = *head;                                                                                 \
            *head = (*head)->next;                                                                              \
            free(temp);                                                                                         \
            return true;                                                                                        \
        }                                                                                                       \
        NAME *temp = (*head)->next;                                                                             \
        NAME *tempPrev = (*head);                                                                               \
        while (temp)                                                                                            \
        {                                                                                                       \
            if (temp->val == val)                                                                               \
            {                                                                                                   \
                tempPrev->next = temp->next;                                                                    \
                if (delete_val)                                                                                 \
                {                                                                                               \
                    delete_val(temp->val);                                                                      \
                }                                                                                               \
                free(temp);                                                                                     \
                return true;                                                                                    \
            }                                                                                                   \
            tempPrev = temp;                                                                                    \
            temp = temp->next;                                                                                  \
        }                                                                                                       \
        return false;                                                                                           \
    }                                                                                                           \
    bool remove_node_SLL_##NAME(NAME **head, NAME *node, bool delete_val(TYPE))                                 \
    {                                                                                                           \
        if (!head || !(*head))                                                                                  \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        if (*head == node)                                                                                      \
        {                                                                                                       \
            return remove_head_SLL_##NAME(head, delete_val);                                                    \
        }                                                                                                       \
        NAME *temp = (*head)->next;                                                                             \
        NAME *tempPrev = *head;                                                                                 \
        while (temp != node && temp != NULL)                                                                    \
        {                                                                                                       \
            tempPrev = temp;                                                                                    \
            temp = temp->next;                                                                                  \
        }                                                                                                       \
        if (temp == NULL)                                                                                       \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        tempPrev->next = temp->next;                                                                            \
        if (delete_val)                                                                                         \
        {                                                                                                       \
            delete_val(temp->val);                                                                              \
        }                                                                                                       \
        free(temp);                                                                                             \
        return true;                                                                                            \
    }                                                                                                           \
    bool find_val_SLL_##NAME(NAME *head, TYPE val, NAME *result) /*To find index of result, traverse manually*/ \
    {                                                                                                           \
        if (!head)                                                                                              \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        while (head)                                                                                            \
        {                                                                                                       \
            if (head->val == val)                                                                               \
            {                                                                                                   \
                result = head;                                                                                  \
                return true;                                                                                    \
            }                                                                                                   \
            head = head->next;                                                                                  \
        }                                                                                                       \
        result = NULL;                                                                                          \
        return false;                                                                                           \
    }                                                                                                           \
    bool is_empty_SLL_##NAME(NAME *head)                                                                        \
    {                                                                                                           \
        return (head == NULL);                                                                                  \
    }                                                                                                           \
    bool delete_SLL_##NAME(NAME **head, bool (*delete_val)(TYPE))                                               \
    {                                                                                                           \
        if (!head || !(*head))                                                                                  \
        {                                                                                                       \
            return false;                                                                                       \
        }                                                                                                       \
        while (!remove_head_SLL_##NAME(head, delete_val))                                                       \
            ;                                                                                                   \
        if (*head == NULL)                                                                                      \
        {                                                                                                       \
            return true;                                                                                        \
        }                                                                                                       \
        return false; /*head double pointer null, to be honest I don;t even know what it means*/                \
    }                                                                                                           \
    bool linear_search_##NAME(NAME *head, bool (*comparator)(TYPE, TYPE), TYPE ref, NAME **foundNode)           \
    {                                                                                                           \
        while (head)                                                                                            \
        {                                                                                                       \
            if (comparator(ref, head->val))                                                                     \
            {                                                                                                   \
                if (foundNode)                                                                                  \
                {                                                                                               \
                    *foundNode = head;                                                                          \
                }                                                                                               \
                return true;                                                                                    \
            }                                                                                                   \
            head = head->next;                                                                                  \
        }                                                                                                       \
        *foundNode = NULL;                                                                                      \
        return false;                                                                                           \
    }

#endif