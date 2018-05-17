#include <stdio.h>
#include "insertion_sort.h"

//Sort array using merge sort
//Complexity:
//         Time
//Best: O(1) Array in sorted order / Worst: O(N^2) reverse order, inner sort from x to 0;
//        Space
//All: O(1): swap pair elements if first larger than second
void insertion_sort(int arr[]){
  int length = sizeof(&arr);
  int wallidx = -1;
  for(int i = 0; i< length; i++){
    if(wallidx == -1){
      wallidx = 0;
    }
    else {
      if(arr[wallidx] > i){
        for(int reverse =i;  reverse>0; reverse--){
          if(arr[reverse-1] > arr[reverse]){
            int temp = arr[reverse];
            arr[reverse] = arr[reverse-1];
            arr[reverse-1] =temp;
          }
          else {
            break;
          }
        }
      }
      wallidx++;
    }
  }
}

int main(void){
  int arr[] = {10,9,8,7,6,5,4,3,2,1};
  insertion_sort(arr);
  for(size_t index=0; index<sizeof(arr)/sizeof(arr[0]); index++){
      printf("%i,",*(arr+index));
  }
  return 0;
}
