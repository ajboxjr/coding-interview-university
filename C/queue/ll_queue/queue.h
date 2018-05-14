#include "../singly_linkedlist/singly_linkedlist.h"
struct Queue;
typedef struct Queue {
    LinkedList ll;
    int size;
} Queue;


char * dequque(Queue * queue);

void enqueue(Queue * queue, char * value);

void printQueue(Queue* queue);
