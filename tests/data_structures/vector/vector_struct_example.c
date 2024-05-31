/**
 * @file vector_struct_example.c
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <string.h>
#include "../../../include/data_structures/vector/vector.h"

struct Student{
    char* name;
    double CGPA;
};

typedef struct Student Student;

Student* new_Student(char* name, uint64_t name_len, double CGPA){
    Student* new_obj = malloc(sizeof(Student));
    if(!new_obj){
        return NULL;
    }
    new_obj->name = calloc(name_len,sizeof(char));
    if(!new_obj->name){
        free(new_obj);
        return NULL;
    }
    strncpy(new_obj->name,name,name_len);
    new_obj->CGPA = CGPA;
    return new_obj;
}

DEFINE_VECTOR(studVector, Student*)

void print_Student(Student* st){
    if(!st){
        printf("NULL entry\n");
        return;
    }
    printf("%10s\t%lf\n",st->name,st->CGPA);
}

int main(void){
    Student* newStud = new_Student("Prathamesh",strlen("Prathamesh"),10.00);
    if(!newStud){
        puts("New student cannot be created");
    }
    studVector* newStudVector = new_studVector(1,NULL);
    if(!new_studVector){
        puts("Vector cannot be initialised");
        return -1;
    }
    if(!set_at_studVector(newStudVector,0,newStud)){
        puts("Invalid index");
        return -1;
    }
    print_studVector(newStudVector,print_Student);
    putchar('\n');
    newStud = new_Student("XYZ",strlen("XYZ"),9.5);
    if(!newStud){
        puts("New student cannot be created");
        return -1;
    }
    if(!add_at_beginning_studVector(newStudVector,newStud)){
        puts("Could not add in vector");
        return -1;
    }
    print_studVector(newStudVector,print_Student);
    putchar('\n');
    newStud = new_Student("ABC",strlen("ABC"),9.0);
    if(!add_at_end_studVector(newStudVector,newStud)){
        puts("Could not add in vector");
        return -1;
    }
    print_studVector(newStudVector,print_Student);
    putchar('\n');
    Student* gotStud;
    const int index = 1;
    if(!at_studVector(newStudVector,index,&gotStud)){
        puts("Invalid index");
        return -1;
    }
    printf("Student at index %d\n",index);
    print_Student(gotStud);
    putchar('\n');
    if(!remove_from_end_studVector(newStudVector,&gotStud)){
        puts("Could not remove student");
    }
    printf("%d\n",newStudVector->size);
    printf("Removed student from end\n");
    print_Student(gotStud);
    putchar('\n');
    print_studVector(newStudVector,print_Student);
    if(!remove_from_beginning_studVector(newStudVector,NULL)){
        puts("Couldn't remove");
    }
    putchar('\n');
    print_studVector(newStudVector,print_Student);
    if(!remove_from_beginning_studVector(newStudVector,NULL)){
        puts("Couldn't remove");
    }
    if(!remove_from_beginning_studVector(newStudVector,NULL)){
        puts("Couldn't remove");
    }
    print_studVector(newStudVector,print_Student);
    return 0;
}