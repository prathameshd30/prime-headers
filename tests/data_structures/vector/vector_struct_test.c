#include <stdio.h>
#include <string.h>

//For manual valgrind testing
#include "../../../include/data_structures/vector/vector.h"

// #include "vector.h"
#include <string.h>

//Type for struct
struct Card{
    char* name;
    uint16_t name_length;
    char suite;
    unsigned short value;
};
typedef struct Card Card;

Card* new_Card(char* name, uint16_t name_length, char suite, unsigned short value){
    Card* new_obj = calloc(1,sizeof(Card));
    new_obj->name = calloc(name_length+1, sizeof(char)); // accounting for null character (thanks valgrind!) (Unsafe if buffer overflow, just for basic testing)
    strncpy(new_obj->name,name,name_length);
    new_obj->name_length = name_length;
    new_obj->suite = suite;
    new_obj->value = value;
    return new_obj;
}

void print_Card(Card* card){
    if(!card){
        return;
    }
    if(!card->name){
        printf("Name null");
    }
    printf("Name - %s\nValue - %d\nSuite - %c\n",card->name,card->value,card->suite);
}

bool delete_Card(Card* card){
    if(!card){
        return false;
    }
    if(card->name){
        free(card->name);
    }
    free(card);
    return true;
}

DEFINE_VECTOR(CardVector, Card*)

int main(void){
    CardVector* cv = new_CardVector(0);
    if(!is_empty_CardVector(cv)){
        puts("Empty Card Vector does not fulfill is_empty");
        return -1;
    }
    if(!add_at_beginning_CardVector(cv, new_Card("Ace of Spades", strlen("Ace of Spades"), 'S', 1))){
        puts("Could not add at beginning");
        return -1;
    }
    // More tests needed
    print_CardVector(cv,print_Card);
    delete_CardVector(cv,delete_Card);
    return 0;
}