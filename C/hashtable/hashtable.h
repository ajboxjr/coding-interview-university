#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

struct HashTable;

typedef struct HashTable {
    struct LinkedList **table;
    long int size;
    long long int values;
} HashTable;

unsigned long long sdbm(char* str );

long int hash(HashTable *ht,char *str);

void init(HashTable *ht, long int size);

void printTable(HashTable *ht);

void getValues(char * valArr[], HashTable *ht);

void deleteTable(HashTable *ht);

void resize(HashTable *ht);

void add(HashTable *ht, char *data);

void freeTable(HashTable *ht, long int size);

// void get(HashTable *ht)

#endif
