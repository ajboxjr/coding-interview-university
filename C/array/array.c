#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "array.h"
#include <stdlib.h>
struct Vector;

//Append item to end of vector
//Complexity: Time-0(1) Space-O(N)
void push(Vector * arr, long int item){
    handle_resize(arr, 1);
    arr->items[arr->size++] = item;
}

//Get size of vector
//Complexity (all) 0(1)
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
void init(Vector * arr, long int max){
    arr->items = calloc(max,sizeof(*arr->items)); 
    arr->cap = max;
}

//Insert item at given position and shift rightbound
//Complexity: Time-0(1) Space-0(...)
void _resize(Vector * arr, double  multiplier){
  arr->items = realloc(arr->items, sizeof(*arr->items)*multiplier);
}

//Double Vector capacity
//Complexity: (all) O(1)
#define resize _resize
void handle_resize(Vector * arr, long int adjust){    
    if((long) arr->size + adjust == arr->cap ){
        printf("double");
        resize(arr, 2);
    }
    else if(adjust == -1 && arr->size + adjust == floor(arr->cap / 4)){
        resize(arr, .5);
    }
}
#undef resize

//Print items in vector array
void printVector(Vector * arr){
    long int length = arr->size;
    for(long int x=0; x<length; x++){
        printf("%i, ",*(arr->items+x));
    }
}

//Add item to beginning of array
//Compexity: Time-0(1) Space-0(N)
void prepend(Vector * arr, int item){
    handle_resize(arr, 1);
    for(long int x=arr->size; x>=0; x--){
        arr->items[x+1] = arr->items[x];
    }
    arr->items[0] = item;
    arr->size++;
}

//Remove last item from array
//Complexity: Time-0(1)
void pop(Vector * arr){
    arr->items[arr->size-1] = 0;
    arr->size--;
}

//Remove item by index;
//Complexity: Time-0(1) / Space-0(
void delete(Vector * arr, long int index){
    handle_resize(arr, -1);
    long int length = arr->size;
    if(length > 1 && index > 0 && index<=length){
        if(length == 1){
            printf("whyy!!!");
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
//Complexity: Time-.....
void remove_item(Vector * arr, int item){
   handle_resize(arr, -1);
   delete(arr, find(arr,item));
}
//Find item from array
//Complexity Time-0(1), Space-0(1) ??
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
    free(array);
    return 0;
}
