#include "../singly_linkedlist/singly_linkedlist.c"
#include "merge_sort.h"

//**Abstract**
//pass in linkedlist struct and reassign to sorted array
//Complexity:
//         Time
//Best: O(1) linkedlist size of 0/1  / Worst: O(N), traverse N elements from sorted.
//        Space
//All: O(1): iterate through sorted linkedlist using pointer
void merge_sort_ll(LinkedList * ll){
  node * n  = merge_sort(ll->start);
  node * ptr = n;
  ll->start = NULL;
  ll->end = NULL;
  while(ptr != NULL){
    push_back(ll, ptr->data);
    ptr = ptr->next;
  }
}

//Recursively Split and merge linkedlist
//Complexity:
//         Time
//Best: O(1) linkedlist size of 1  / Worst: O(nlogN), recurively split linked list of N (n/2..n/4) and sort
//        Space
//Best: O(1): return linekdlist of 1  / Worst: O(N), recurively store left right and merge
node * merge_sort(node * n){
  node *result;
  node *front, *back;
  //determine wheter it can be sorted, greater than 1 node.
  if (n->next != NULL){
    split(n, &front, &back);

    //Recursively split to node each then sort..
    merge(&result, merge_sort(front), merge_sort(back));
    return result;
  }
  return n;
}

//Split linkedlist into two lists
//Complexity:
//         Time
//Best: O(1) list contains 2 items / Worst: O(N), traverse N elements
//        Space
//All: O(1): pointers to left half and right half of list
void split(node * list, node **left, node ** right){
  if(list){
    node * slow, * fast;
    slow = list;
    fast = list->next;
    while (fast != NULL){
      fast = fast->next;
      if (fast != NULL){
          slow = slow->next;
          fast = fast->next;
      }
    }
    *left = list;
    *right = slow->next;
    slow->next = NULL;
    // printf("%s %s\n", (*left)->data, (*right)->data);
  }
}

//Recusively sort and merge left and right halves of list
//Complexity:
//         Time
//Best: O(1) left or right list contains 1 node / Worst: O(L+R), recusively add smallest element to result
//        Space
//Best: O(1), store 1 node to result / Worst: O(N), each call storing node to result
void merge(node ** result, node *left, node *right){
  if (left == NULL || right == NULL){
    if(left == NULL){
      *result = right;
    }
    if(right == NULL){
      *result = left;
    }
  }
  else {
    //left greater
    if(strcmp(left->data, right->data) < 0){
      *result = left;
      merge(&(*result)->next, left->next, right);
    }
    if(strcmp(left->data, right->data) >= 0){
      *result = right;
      merge(&(*result)->next, left, right->next);
    }
  }
}

int main(void){
  LinkedList * ll = calloc(1,sizeof(*ll));
  LinkedList * sorted;
  push_back(ll, "one");
  push_back(ll, "cheese");
  push_back(ll, "maybe ints..");
  push_back(ll, "83");
  push_back(ll, "alphabet");
  push_back(ll, "body wash");
  push_back(ll, "wiishy wash");
//Using node struct
  node *n = merge_sort(ll->start);
  while(n != NULL){
    printf("%s ", n->data);
    n = n->next;
  }
//--------or using LinkedList struct -----------
  // merge_sort_ll(ll);
  // printLinkedList(ll);

  free(ll);
  free(sorted);
  return 0;
}
