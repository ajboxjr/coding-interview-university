#include <stdio.h>
#include "queue.h"
#include "../singly_linkedlist/singly_linkedlist.c"
#include "../singly_linkedlist/singly_linkedlist.h"

struct Queue;
// void initQueue(Queue * queue){
//
// }

//Remove item from head of the queue
//Complexity:
//         Time
//All(1): Acees start of queue
//        Space
//All O(1):  return previous start node
char * dequque(Queue * queue){
   return pop_front(&queue->ll);
}

//Add item to the tail of the queue
//Complexity:
//         Time
//All(1): acessing head & tail
//        Space
//All O(1): appending to tail
void enqueue(Queue * queue, char * value){
    push_back(&queue->ll, value);
}
//Decoration, print queue
void printQueue(Queue* queue){
    printLinkedList(&queue->ll);
}

int main(void){
    Queue * queue = calloc(1,sizeof(* queue));
    // initQueue(queue);
    enqueue(queue, "one");
    enqueue(queue, "zero");
    printf("%s",dequque(queue));
    printQueue(queue);
    free(queue);
    return 0;
}
