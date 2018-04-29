#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "singly_linkedlist.h"

//Free Data & Node
void setData(node * n, char *data) {
    char *copy= malloc(strlen(data)+1);
    strcpy(copy, data);
    n->data = copy;
    n->next = NULL;
}


void initLinkedList(LinkedList *ll){
    ll->start = NULL;
    ll->end = NULL;
    ll->length = 0;
}


bool isEmpty(LinkedList *linked){
    return (!linked->start || !linked->end);
}


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

void prepend(LinkedList *linked, char *data){
    node *n = malloc(sizeof(* n));
    setData(n, data);
    if (isEmpty(linked)){
        linked->start = n;
        linked->end = n;
    }
    else {
        n->next = linked->start;
        linked->start = n;
    }
    linked->length += 1;
}

//Find first index of item in array, else return -1
//Complexity: Time-O(N), Space-0(N)
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

// void remove(LinkedList * ll, char * item){
//     if(strcmp(ll->start, item) == 0){
//         ll->start = ll->start->next;
//     }
//     for(node *ptr= ll->start; ptr->next != NULL; ptr=ptr->next){
//         if(strcmp(ptr->data, item) == 0){
//             ptr = ptr->next;
//             if(ptr-> next == NULL){
//                 ll->end = ptr;
//             }
//         }
//     }
//     if(strcmp(ll->end, item) == 0){
//         ll->end = ll->end
//     }
// }

void append(LinkedList *linked, char *data){
    node *n = malloc(sizeof(* n));
    setData(n, data);
    if(isEmpty(linked)){
        linked->start = n;
        linked->end = n;
    }
    else{
            linked->end->next = n;
            linked->end = n;
    }
    linked->length +=1;

}


//Return a copy of all values in LinkedList;
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
void freeValues(char *values[], long long length){
    for(long long x=0;x<length;x++){
        free(values[x]);
    }
}


void printLinkedList(LinkedList *ll){
    for(node *ptr= ll->start; ptr != NULL; ptr=ptr->next){
        printf("%s ", ptr->data);
    }
}


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

int main(void){
    LinkedList *ll = calloc(1,sizeof(*ll));
    initLinkedList(ll);
    append(ll, "hello");
    append(ll, "world");
    append(ll,"cheese");
    append(ll,"monkey");
    append(ll,"money");
    prepend(ll, "mindfield");
    printLinkedList(ll);
    // contains(ll,"hello");
    deleteLinkedList(ll);
    free(ll);
    return 0;
}
