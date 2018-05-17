#include <stdbool.h>
#include <stdio.h>
#include "bubble_sort.h"

//Determine whether array is sorted
//Complexity:
//         Time
//All: O(1) traverse through arr
//        Space
//All: O(N) compare element pairs
bool is_sorted(int * arr, int size){
  for(size_t i = 0; i<=size; i++){
    if(arr[i] >= arr[i+1]){
      return false;
    }
  }
  return true;
}

//Determine whether array is sorted
//Complexity:
//         Time
//Best: O(1) Array in sorted order / Worst: O(N^2) Array in reversely sorted
//        Space
//All: O(N): swap pair elements if first larger than second
void bubble_sort(int arr[]){
  int length = sizeof(&arr);
  int iters = 0;
  while(!is_sorted(arr,length)){
    iters++;
    for(size_t i = 0; i<=length; i++){
      printf("\n%i - %i", arr[i] ,arr[i+1]);
      if(*(arr+i) >= *(arr+i+1)){
        // printf("%i",arr[i]);
        int temp = *(arr+i);
        *(arr+i) = *(arr+i+1);
        *(arr+i+1) = temp;
      }
    }
  }
  printf("\n%i iterations\n", iters);
}

int main(void){
  int arr[] = {10,9,8,7,6,5,4,3,2,1 };
  bubble_sort(arr);
  for(size_t index=0; index<sizeof(arr)/sizeof(arr[0]); index++){
      printf("%i,",*(arr+index));
  }
  return 0;
}
