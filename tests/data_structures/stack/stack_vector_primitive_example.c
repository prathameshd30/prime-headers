/**
 * @file stack_primitive_example.c
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-31
 * 
 * 
 */
#include <stdio.h>

#include "../../../include/data_structures/stack/stack_vector.h"

DEFINE_STACK_VECTOR(charStack,char)

void print_char(char c){
    printf("%c ",c);
}

int main(void){
    char s[] = "()(())";
    charStack* cs = new_charStack(0);
    for(int i = 0; i<sizeof(s)/sizeof(char); ++i){
        print_charStack_vector(cs->vec,print_char);
        putchar('\n');
        if(s[i]=='('){
            push_charStack(cs,'(');
        }
        else if(s[i]==')'){
            if(!pop_charStack(cs,NULL)){
                printf("Invalid string\n");
                return 0;
            }
        }
    }
    if(!isEmpty_charStack(cs)){
        printf("Invalid string\n");
        return 0;
    }
    printf("Valid string\n");
}