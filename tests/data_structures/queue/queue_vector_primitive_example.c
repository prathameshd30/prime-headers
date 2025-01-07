#include <stdio.h>
#include "../../../include/data_structures/queue/queue_vector.h"

DEFINE_QUEUE_VECTOR(intQ, intVec, int)

void print_int(int a){
    printf("%d ",a);
}

int main(void){
    intQ* newQ = new_intQ(0);
    enqueue_intQ(newQ,0);
    enqueue_intQ(newQ,1);
    print_intVec(newQ->vec,print_int);
    int a;
    dequeue_intQ(newQ,&a);
    printf("\n%d\n",a);
    print_intVec(newQ->vec,print_int);

}