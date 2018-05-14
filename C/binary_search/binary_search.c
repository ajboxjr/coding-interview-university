#include "../array/array.c"
// #include "../array/array.h"

struct Vector;

//Recursively search for value
//Complexity:
//         Time
//All: O(1) one item == value / Worst: O(logN), length by N eatch iteration
//        Space
//All: O(N) store mid each iteration
int rec_binary_search(Vector * arr, int low, int high, int value){
  printf("%i ... %i", low, high);
  if(low<=high){
      int mid = (low+high)/2;
      int arrVal = at(arr,mid);
      printf("%i-%i\n", arrVal, value);
      if(arrVal > value){
        high = mid-1;
      }
      else if(arrVal < value){
        low = mid+1;
      }
      else{
        return mid;
      }
      return rec_binary_search(arr, low,high, value);

    }
    return -1;
}

//Iteraively search for value
//Complexity:
//         Time
//All: O(1) one item / Worst: O(logN), length by N eatch iteration
//        Space
//All: O(1) store mid
int iter_binary_search(Vector * arr, int value){
  int low = 0;
  int mid, arrVal;
  int high = arr->size;
  while(low <= high){
    mid = (low+high)/2;
    arrVal = at(arr,mid);
    printf("%i-%i\n", arrVal, value);
    if(arrVal > value){
      high = mid-1;
    }
    else if(arrVal < value){
      low = mid+1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

//Binary search algorithims
int binary_search(Vector * arr, int value){
  // return rec_binary_search(arr, 0, arr->size, value);
  return iter_binary_search(arr, value);
}

int main(void){
  Vector array;
  init(&array,10);
  push(&array,2);
  push(&array,3);
  push(&array,4);
  push(&array,7);
  push(&array,9);
  push(&array,20);
  printVector(&array);
  int val = binary_search(&array, 20);
  printf("%i", val);

}
