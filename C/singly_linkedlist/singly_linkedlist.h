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

void setData(node * n, char *data);

void append(LinkedList *linked, char *data);

void initLinkedList(LinkedList *ll);

void printLinkedList(LinkedList *ll);

void values(char *valArr[], LinkedList *ll);

bool isEmpty(LinkedList *linked);

bool contains(LinkedList *ll, char *entry);

#endif
