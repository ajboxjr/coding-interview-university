#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>


struct node;
struct linked;

typedef struct node{
    char *data;
    struct node *next;
}node;

typedef struct LinkedList{
    node * start;
    node * end;
    int length;
}LinkedList;

void deleteLinkedList(LinkedList * ll);

void setData(node * n, char *data);

void initLinkedList(LinkedList *ll);

void printLinkedList(LinkedList *ll);

bool empty(LinkedList *linked);

bool contains(LinkedList *ll, char *entry);

char * value_at(LinkedList * linked, int index);

void push_front(LinkedList *linked, char *data);

char * pop_front(LinkedList * linked);

char * pop_back(LinkedList * linked);

void push_back(LinkedList *linked, char *data);

char * front(LinkedList * linked);

char * back(LinkedList * linked);

void insert(LinkedList * linked, int index, char * value);

int find(LinkedList * ll, char * data);

void erase(LinkedList * ll, int index);

void remove_value(LinkedList * ll, char * item);

void values(char *valArr[], LinkedList *ll);

void freeValues(char *values[], long long length);

char * value_n_from_end(LinkedList * ll, int index);

LinkedList * reverse(LinkedList * ll);

void freeNode(node * n);

#endif
