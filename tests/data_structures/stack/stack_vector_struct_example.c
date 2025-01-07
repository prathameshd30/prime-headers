#include <stdio.h>
#include "../../../include/data_structures/stack/stack_vector.h"

struct Card{
    char suit;
    char val;
};
typedef struct Card Card;

void print_card(Card* a){
    printf("%c %c\n",a->suit,a->val);
}

bool delete_card(Card* c){
    free(c);
    return true;
}

DEFINE_STACK_VECTOR(cardStack, cardVec,Card*)

int main(void){
    cardStack* cs = new_cardStack();
    Card* newCard = malloc(sizeof(Card));
    newCard->suit = 'S'; //Spades
    newCard->val = 'A'; //Ace
    push_cardStack(cs,newCard);
    newCard = malloc(sizeof(Card));
    newCard->suit = 'H'; //Hearts
    newCard->val = 'K'; //King
    push_cardStack(cs,newCard);
    print_cardStack(cs,print_card);
    pop_cardStack(cs,delete_card);
    pop_cardStack(cs,delete_card);
    putchar('\n');
    print_cardStack(cs,print_card);
    if(!pop_cardStack(cs,delete_card)){
        printf("Empty stack, cannot remove\n");
    }
}