#include <stdbool.h>

struct Queue;

typedef struct Queue {
    char ** list;
    int size;
    int start;
    int end;
} Queue;

void initQueue(Queue * q, int size);

char * dequque(Queue * queue);

void enqueue(Queue * queue, char * value);

void printQueue(Queue* queue);

bool full(Queue * queue);

bool empty(Queue * queue);
/*
| | | |
0 1 2 3
*/
