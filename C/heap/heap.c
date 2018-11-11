#include <stdbool.h>
#include "heap.h"
#include <math.h>
#include <stdio.h>
// #include "../array/array.h"
#include "../array/array.c"

long int get_size(Vector * heap){
  return heap->size-1;
}

void sift_up(Vector * heap){
  if(!is_empty(heap)){
    long int parent_idx;
    long int length = heap->size;
    long int curr_idx = length-1;
    // printf("%li\n", length);
    parent_idx = (curr_idx-1)/2;
    while(parent_idx > 0){
      long int curr = heap->items[curr_idx];
      long int parent = heap->items[parent_idx];
      if(parent < curr){
        // printf("%li\n",parent_idx );
        swap(heap,curr_idx,parent_idx);
        curr_idx = parent_idx;
        parent_idx = (curr_idx-1)/2;
      }
      else{
        break;
      }
    }
    if(heap->items[curr_idx] > heap->items[parent_idx]){
      swap(heap, curr_idx, parent_idx);
    }
  }
}

void sift_down(Vector * heap){
  long int length = heap->size;
  //replace root with last child;
  int parent = 0;
  heap->items[0] = pop(heap);
  printf("head%i\n", heap->items[0]);
  //Base
  while(parent < length){
    long int child_left = (2*parent)+1;
    long int child_right = (2*parent)+2;
    //Check for both left & right
    if(child_right < length){
      printf("%i,%i\n",heap->items[child_left], heap->items[child_right]);
      if (heap->items[child_right] > heap->items[child_left]){
          swap(heap, parent, child_right);
          printf("asd\n");
          parent = child_right;
      }
      else {
        // printf("asd\n");
        swap(heap, parent, child_left);
        parent = child_left;
      }
    }
    //Checkf for left child
    else if(child_left < length){
      swap(heap, parent, child_left);
        parent = child_left;
    }
    //No Children
    else {
      break;
      printVector(heap);

    }
  }
}

int get_max(Vector * heap){
  if(is_empty(heap)){
    return -1;
  }
  else {
    return heap->items[0];
  }
}
void insert(Vector * heap, long int value){
  push(heap,value);
  sift_up(heap);
}

Vector * heapify(int arr[], int length){
  Vector * heap = calloc(1, sizeof(*heap));
  init(heap, 4);
  for(int i=0; i<length; i++){
    insert(heap, arr[i]);
  }
  return heap;
}

int extract_max(Vector * heap){
  if(is_empty(heap)){
    return -1;
  }
  else {
    int temp = heap->items[0];
    sift_down(heap);
    return temp;
  }
}
int * heap_sort(int arr [], int length){
  int * sorted_arr = malloc(length* sizeof(int));
  Vector * heap = heapify(arr, length);
    for(int i = 0; i<length; i++){
      sorted_arr[i] = extract_max(heap);
    }
    printVector(heap);
    return sorted_arr;
}
int main(void){
  Vector *heap = calloc(1,sizeof(*heap));
  init(heap,8);
  insert(heap, 1);
  insert(heap, 4);
  insert(heap, 6);
  // insert(heap, 7);
  // insert(heap,2);
  // insert(heap,5);
  // insert(heap,4);
  // extract_max(heap);
  int arr [] = {6,4,5,1,3};
  Vector *newheap = heapify(arr,5);
  int *m = heap_sort(arr,5);
  // for(int z=0; z<5;z++){
  //   printf("%i", m[z]);
  // }

  printVector(newheap);
  // printf("%i\n", get_max(heap) );
  // printVector(heap);
}
