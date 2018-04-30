#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "array.h"
#include <stdlib.h>
struct Vector;

//Append item to end of vector
//Complexity:
//         Time
//All: O(1) insert to end of array, or resized array
//        Space
//All: O(1) store temp node
void push(Vector * arr, long int item){
    handle_resize(arr, 1);
    arr->items[arr->size++] = item;
}

//Get size of vector
//Complexity: (all) 0(1)
long int size(Vector * arr){
    return arr->size;
}

//Get total number of items the vector can hold
//Complexity: (all) 0(1)
long int capacity(Vector * arr){
    return arr->cap;
}

//Return whether vector contains items
//Complexity: (all) 0(1)
bool is_empty(Vector * arr){
    return arr->cap > 0;
}

//Return the index of item or -1 if none
//Complexity: (all) 0(1)
long int at(Vector * arr, long int pos){
    return *(arr->items+pos);
}

//Initialize Array size items
//Complexity:
//All: O(1) store temp node
void init(Vector * arr, long int max){
    arr->items = calloc(max,sizeof(*arr->items));
    arr->cap = max;
}

//Insert item at given position and shift rightbound
//Complexity: Time-0(N*M), looping over new elemt size / Space-0(N*m), storing N*multipler elements
void _resize(Vector * arr, double  multiplier){
  arr->items = realloc(arr->items, sizeof(*arr->items)*multiplier);
}

//Double Vector capacity
//Complexity:
//         Time
//Best: O(1), no resize, worst O(N*M), loop over reajusted length
//        Space
//All: O(1) Compare readjusted size
#define resize _resize
void handle_resize(Vector * arr, long int adjust){
    if((long) arr->size + adjust == arr->cap ){
        resize(arr, 2);
    }
    else if(adjust == -1 && arr->size + adjust == floor(arr->cap / 4)){
        resize(arr, .5);
    }
}
#undef resize

//Print items in vector array
// Complexity
//        Time
//Best: O(1) iterate over 0/1 element/ Worst: O(N) iterate over N elements
//        Space
//All O(1)- printing value
void printVector(Vector * arr){
    long int length = arr->size;
    for(long int x=0; x<length; x++){
        printf("%i, ",*(arr->items+x));
    }
}

//Add item to beginning of array
// Complexity
//        Time
//Best: O(1) iterate over 0/1 element/ Worst: O(N) iterate over N elements
//        Space
//Best O(1)- O shift 0/1 elements Worst: O(N-1), shift N-1 Elements
void prepend(Vector * arr, int item){
    handle_resize(arr, 1);
    for(long int x=arr->size; x>=0; x--){
        arr->items[x+1] = arr->items[x];
    }
    arr->items[0] = item;
    arr->size++;
}

//Remove last item from array
//Complexity:
//         Time
//Best: O(1), one node Worst: / O(N) n-consectuive nodes
//        Space
//All: O(1) store temp node
void pop(Vector * arr){
    if(arr->size > 0){
      handle_resize(arr,-1);
      arr->items[arr->size-1] = 0;
      arr->size--;
    }
}

//Remove item by index;
//Complexity:
//         Time
//Best: O(1), 1 item or final item / Worst: O(N) shifting memory locations after delete
//        Space
//All: Best 0(1) deleteing 2nd to last item reposiging last item, Worst 0(N-1) resassinging all elements
void delete(Vector * arr, long int index){
    handle_resize(arr, -1);
    long int length = arr->size;
    if(length > 1 && index > 0 && index<=length){
        if(length == 1){
            arr->items[1] = 0;
        }
        else if(length >1){
            for(long int x=index; x<=length; x++){
                if(index != length){
                    arr->items[x] = arr->items[x+1];
                }
            }
        }
        arr->size--;
    }
}

//Remove item from array
//Complexity:
//         Time
//Best: O(1), Single element / Worst: O(N) last element
//        Space
//Best O(1) if final element or not found, O(N), if first element shift N-1 elements
void remove_item(Vector * arr, int item){
  int index = find(arr,item); //O(N)
    if(index != -1){
      handle_resize(arr, -1);
      delete(arr, find(arr,item)); //O(1)
    }
}

//Find item from array
//Complexity:
//         Time
//Best: O(1), at first element: / O(N) final element or not found
//        Space
//All: O(1) comparing array value to item
int find(Vector * arr, int item){
    long int length = arr->size;
    for(long int x=0; x<length; x++){
        if(arr->items[x] == item){
            return x;
        }
    }
    return -1;
}

int main(void){
    Vector array;
    init(&array,6);
    push(&array,2);
    push(&array,3);
    push(&array,4);
    push(&array,7);
    prepend(&array,1);
    remove_item(&array, 7);
    pop(&array);
    find(&array, 7);
    printVector(&array);
    return 0;
}
