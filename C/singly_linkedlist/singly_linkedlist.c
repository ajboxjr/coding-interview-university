#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "singly_linkedlist.h"

//Defualt Return type for char * fucntion
static char s = '\0';

//Free memory for associated LinkedList
//Complexity:
//         Time
//Best: O(1), one node / Worst: O(N) n-consectuive nodes
//        Space
//Best: O(1), 1 temporaiy store and free node /  Worst O(N), freeing N nodes
void deleteLinkedList(LinkedList * ll){
    node *ptr = ll->start;
    while(ptr){
        node *temp = ptr;
        if(temp->data){
            free(temp->data);
        }
        ptr = ptr->next;
        free(temp);
    }
    ll->length= 0;
 }

//Assingn to node data
//         Time
//Worst: O(1), map over 1 char, O(N), map over N elements
//        Space
//All O(N): creating memory for n chars and storing data
 void setData(node * n, char *data) {
     char *copy= malloc(strlen(data)+1);
     strcpy(copy, data);
     n->data = copy;
     n->next = NULL;
 }

//Return bool whether linkedlist is empty
//Complexity:
//         Time
//All(1): 1 step compare
//        Space
//All O(1): returning boolean
bool empty(LinkedList *linked){
    return (!linked->start && !linked->end);
}

//Return pointer to a string
//Complexity:
//         Time
//Best: O(1) empty or 1 value Worst: O(N) multiple nodes in array
//        Space
//All: O(1): 1 temporaiy node
char * value_at(LinkedList * linked, int index){
  node *ptr = linked->start;
  for(int x = 0; x<index; x++){
      if(x == index){
           return &(*ptr->data);
      }
     ptr=ptr->next;
  }
  return &s;
}

//Complexity:
//         Time
//All 0(1)
//        Space
//All O(1) Storing node, assinging to LinkedList
void push_front(LinkedList *linked, char *data){
    node *n = malloc(sizeof(* n));
    setData(n, data);
    if (empty(linked)){
        linked->start = n;
        linked->end = n;
    }
    else {
        n->next = linked->start;
        linked->start = n;
    }
    linked->length += 1;
}

//Remove node and return value
//Complexity:
//         Time
//All O(1), acess start element
//        Space
//All O(1) remove and store start node of LinkedList
char * pop_front(LinkedList * linked){
    char * item = malloc(strlen(linked->start->data)+1);
    if(!empty(linked)){
      strcpy(item, linked->start->data);
      if(linked->length ==1){
        freeNode(linked->start);
        linked->end = NULL;
      }
      else {
        node * temp = linked->start;
        linked->start = linked->start->next;
        freeNode(temp);
      }
      linked->length--;
    }
    return item;
}

//Complexity:
//         Time
//Best: O(1) One node LinkedList, Worst: O(N-1) loop to 2nd to last node to tail
//        Space
//All O(1), Storing temporaiy store Node(ptr) and deleted node item
char * pop_back(LinkedList * linked){
  char * item = malloc(strlen(linked->end->data)+1);
  if(!empty(linked)){
    strcpy(item, linked->end->data);
    if(linked->length ==1){
      free(linked->start);
      free(linked->end);
    }
    else {
      node * ptr = linked->start;
      while(ptr){
        //Second to last element
        if(ptr->next->next == NULL){
          freeNode(ptr->next);
          ptr->next = NULL;
          linked->end = ptr;
          break;
        }
        ptr = ptr->next;
      }
    }
    linked->length--;
  }
  return item;
}

//Complexity:
//         Time
//All O(1): accessing LinkedList tail
//        Space
//All O(1): Storing node to tail
void push_back(LinkedList *linked, char *data){
    node *n = malloc(sizeof(* n));
    setData(n, data);
    if(empty(linked)){
      linked->start = n;
      linked->end = n;
    }
    else{
      linked->end->next = n;
      linked->end = n;
    }
    linked->length +=1;
}

//Return data at the begining of linkedlist
//Complexity:
//         Time
//All O(1): accessing linkedlist start
//        Space
//All O(1) storing to char pointer
char * front(LinkedList * linked){
  char * item;
  strcpy(item, linked->start->data);
  return item;
}


//Complexity:
//         Time
//All O(1), accessing linkedlist end
//        Space
//All O(1) storing to char pointer
char * back(LinkedList * linked){
  char * item;
  strcpy(item, linked->end->data);
  return item;
}


//Insert data at index in LinkedList
//         Time
//Best: 0(1), first or last / Worst: O(N-1), inserting at 2nd last element
//        Space
//All: O(1), creating and appeding node, / Worst: O(N) storing node pointer
void insert(LinkedList * linked, int index, char * value){
  int length = linked->length;
  if(index < length){
    if(index == 0){
      push_front(linked, value);
    }
    else if(index == length-1){
      push_back(linked, value);
    }
    else {
      node * n = malloc(sizeof(* n));
      setData(n, value);
      node * ptr = linked->start;
      int counter = 0;
      while(ptr){
        //ptr->next == desired node
        if(counter+1 == index){
          n->next = ptr->next;
          ptr->next = n;
          break;
        }
        ptr = ptr->next;
        counter++;
      }
    linked->length +=1;
    }
  }
}

//Find first index of item in array, else return -1
//Complexity:
//         Time
//Best: 0(1), first or last / Worst: O(N), inserting at 2nd last element
//        Space
//All: O(1), compare LinkedList item to data
int find(LinkedList * ll, char * data){
    int counter =0;
    for(node *ptr= ll->start; ptr != NULL; ptr=ptr->next){
        if (strcmp(ptr->data, data) ==0){
            return counter;
        }
        counter ++;
    }
    return -1;
}

//Remove item at index from array
//Complexity:
//         Time
//Best: 0(1), first or last index / Worst: O(N-1), removing 2nd last element
//        Space
//Best: 0(1), freeing first or last index  / Worst, O(1), assigning node ptr
void erase(LinkedList * ll, int index){
  int length = ll->length;
  if(index < length){
    if(index == 0){
      free(pop_front(ll));
    }
    if(index == length-1){
      //free data
      free(pop_back(ll));
    }
    else {

      node * ptr = ll->start;
      int counter = 0;
      while(ptr){
        if(counter+1 == index){
          node * temp = ptr->next->next;
          free(ptr->next->data);
          free(ptr->next);
          ptr->next = temp;
          break;
        }
        ptr = ptr->next;
        counter++;
      }
        ll->length--;
    }
  }
}

//Remove value in LinkedList
//Complexity:
//         Time
//Best: 0(1), remove first index / Worst: O(N-1), removing final index
//        Space
//All: O(1), allocate space for ptr, start, next, or end
void remove_value(LinkedList * ll, char * item){
  int length = ll->length;
    if(strcmp(ll->start->data, item) == 0){ //0(N)
        ll->start = ll->start->next;
    }
    node * ptr = ll->start;
    while(ptr->next != NULL){
      if(strcmp(ptr->next->data, item) == 0){
        node *temp = ptr->next;
        ptr->next = ptr->next->next;
        free(&temp);
        if(ptr -> next->next == NULL){
          ll->end = ptr->next;
        }
      }
      ptr = ptr->next;
    }
    ll->length--;
}

//Free associated node and value
void freeNode(node * n){
    free(n->data);
    free(n);
}
//Return a copy of all values in LinkedList
//Complexity:
//         Time
//Best: 0(1), iterate first index / Worst: O(N), iterate over N elements
//        Space
//Best O(1): 1 node   / Worst: O(N), allocate N space for data
void values(char *valArr[], LinkedList *ll){
    int x = 0;
    for(node *ptr= ll->start; ptr != NULL; ptr=ptr->next){
      valArr[x] = calloc(strlen(ptr->data)+1, sizeof(char));
      // malloc(strlen(ptr->data)*sizeof(char));//???
      strcpy(valArr[x],ptr->data);
      // valArr[x] = ptr->data;
      x++;
    }
}

//Return a copy of all values in LinkedList
//Complexity:
//         Time
//Best: 0(1), 1 value / Worst: O(N), iterate over N elements
//        Space
//Best: O(1), 1 temporaiy store and free node / Worst O(N), freeing N nodes
void freeValues(char *values[], long long length){
  for(long long x=0;x<length;x++){
    free(values[x]);
  }
}

//Print elements of linked list array
void printLinkedList(LinkedList *ll){
  for(node *ptr= ll->start; ptr != NULL; ptr=ptr->next){
    printf("%s ", ptr->data);
  }
  printf("\n");
}


//Return whether item in LinkedList
//Complexity:
//         Time
//Best: 0(1), one node / Worst: O(N), At final element or not found
//        Space
//All: O(1), comparing data
bool contains(LinkedList *ll, char *entry){
  if(ll->start){
    for(node *ptr= ll->start; ptr != NULL; ptr=ptr->next){
      if(strcmp(ptr->data, entry) == 0){
          return true;
      }
    }
    return false;
  }
  return false;
}

//Return value n items from end
//Complexity:
//         Time
//Best: 0(1), one node / Worst: O(N), At final element or not found
//        Space
//All: O(1), comparing data
char * value_n_from_end(LinkedList * ll, int index){
  int length = ll->length;
  if(index < length){
    return value_at(ll,(length-1)-index);
  }
  return &s;
}

//Return a reversed linked List
//Complexity:
//         Time
//Best: 0(1), iterate one node / Worst: O(N), iterate At final element or not found
//        Space
//All: O(1), prepending node to LL
LinkedList * reverse(LinkedList * ll){
  LinkedList * reverse = calloc(1, sizeof(*reverse));
  for(node * ptr = ll->start; ptr != NULL; ptr = ptr->next){
    push_front(reverse, ptr->data);
  }
  return reverse;
}


// int main(void){
//   LinkedList *ll = calloc(1,sizeof(*ll));
//   push_back(ll, "1");
//   push_back(ll, "2");
//   push_back(ll, "3");
//   push_back(ll, "4");
//   push_back(ll, "5");
//   push_front(ll, "0");
//
//   printLinkedList(ll);
//
//   free(pop_front(ll));
//   free(pop_back(ll));
//   printLinkedList(ll);
//
//   erase(ll, 2);
//   insert(ll, 1,"-1");
//   printLinkedList(ll);
//
//   printf("\n %s", value_at(ll,3));
//   printLinkedList(ll);
//
//   printf("%s\n",value_n_from_end(ll, 1) );
//
//   remove_value(ll, "money");
//   printLinkedList(ll);
//
//   LinkedList *reversedL  = reverse(ll);
//   printLinkedList(reverse(reversedL));
//
//   deleteLinkedList(reversedL);
//   free(&reversedL);
//   deleteLinkedList(ll);
//   free(ll);
//
//   return 0;
// }
