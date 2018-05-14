#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include "queue.h"

struct Queue;

static char s = 's';

//Initialize Queue
//Complexity:
//         Time
//All: O(1)
//        Space
//All: O(N), store n char pointers
void initQueue(Queue * q, int size){
  q->list = calloc(size, sizeof(char*));
  q->size = size;
  q->start = -1;
  q->end = -1;
}

//Remove item from start of Queue
//Complexity:
//         Time
//All: O(1)
//        Space
//All: O(1), store * start pointer or empty pointer
char * dequque(Queue * queue){
  if(!empty(queue)){
    char * item = queue->list[queue->start];
    //Read final string and set to empty
    item = queue->list[queue->start];
    if( queue->start == queue->end){
      queue->list[queue->start] = NULL;
      queue->start = -1;
      queue->end = -1;
    }
    else {
      //Empty index and move
      queue->list[queue->start] = NULL;
      queue->start = move(queue, queue->start, 1);
    }
    return item;
  }
  printf("empty");
  return &s;
}

//Complexity:
//         Time
//All: O(1)
//        Space
//All: O(1), access size and return new index
int move(Queue* queue, int  loc, int step){
  return (loc + step) % queue->size;
}

//Add item to tail of Queue
//Complexity:
//         Time
//All: O(1)
//        Space
//Worst: O(1) full array, Best O(N) store N characters to memory.
void enqueue(Queue * queue, char * value){
  if(!full(queue)){
    char * item = calloc(1,strlen(value)+1);
    strcpy(item,value);
    if(empty(queue)){
      //move to start index
      queue->start = 0;
      queue->end = 0;
    }
    else {
      queue->end = move(queue, queue->end, 1);
    }
    queue->list[queue->end] = item;
  }
  else {
    printf("full\n");
  }
}

//**Abstract** Print items in array
//Complexity:
//         Time
//Best: O(1), 1 item, Worst O(N), traverse N items
//        Space
//Best: O(1), store index
void printQueue(Queue* queue){
  int index = queue->start;
  int end = queue->end;
  if(!empty(queue)){
    while(index != end ){
      printf("%s\t", queue->list[index]);
      index = (index + 1) % queue->size;
    }
    printf("%s\t", queue->list[index]);
  }
}

//Determine whether queue is full
//Complexity:
//         Time
//All: O(1)
//        Space
//All: O(1), access end+1 and start
bool full(Queue * queue){
  // return (queue->size == queue->length);
  return (move(queue, queue->end,1) == queue->start);
  return true;
}

//Determine wheter queue is empty
//Complexity:
//         Time
//All:: O(1)
//        Space
//Best: O(1) access start and end and compare
bool empty(Queue * queue){
  return (queue->start == -1 && queue->end == -1);
}

int main(void){
  Queue q;
  initQueue(&q, 3);
  enqueue(&q, "hello");
  enqueue(&q, "goodbye");
  enqueue(&q, "sadf");
  enqueue(&q, "candy");
  // enqueue(&q, "flowers");
  // enqueue(&q, "water");

  free(dequque(&q));
  free(dequque(&q));
  free(dequque(&q));
  // free(dequque(&q));

  printQueue(&q);
  free(q.list);
  return 0;
}
