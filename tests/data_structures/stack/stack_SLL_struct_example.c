/**
 * @file stack_SLL_struct_example.c
 * @author Prathamesh Deshpande
 * @brief 
 * @version 0.1
 * @date 2024-05-31
 * 
 * 
 */

#include <stdio.h>
#include <string.h>
#include "../../../include/data_structures/stack/stack_SLL.h"

struct Card{
    char* name;
    uint64_t name_len;
    char suit;
    char val;
};

typedef struct Card Card;

Card* new_Card(char* name, uint64_t name_len, char suit, char val){
    Card* card = malloc(sizeof(Card));
    card->name = calloc(name_len,sizeof(char));
    strncpy(card->name,name,name_len);
    card->suit = suit;
    card->val = val;
    return card;
}

bool delete_Card(Card* card){
    free(card->name);
    free(card);
    return true;
}

DEFINE_STACK_SLL(cardStack, cardNode, Card*)

void print_card(Card* card){
    printf("%c\t%c\t%s\n",card->suit,card->val,card->name);
}

int main(void){
    cardStack* cs = new_cardStack();
    Card* newCard = new_Card("Ace of Spades",strlen("Ace of Spades"),'S','A');
    push_cardStack(cs,newCard);
    newCard = new_Card("King of Hearts",strlen("King of Hearts"),'H','K');
    push_cardStack(cs,newCard);
    print_cardStack(cs,print_card);
    pop_cardStack(cs,delete_Card);
    putchar('\n');
    print_cardStack(cs,print_card);
}
