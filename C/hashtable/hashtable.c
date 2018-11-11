#include <stdio.h>
#include <stdlib.h>
#include "../singly_linkedlist/singly_linkedlist.h"
#include "../singly_linkedlist/signly_linkedlist.c"
#include "hashtable.h"
struct HashTable;

//SDBM Hash function

unsigned long long sdbm(char* str )
{
    // unsigned long hash = 5381;
    unsigned long hash = 0;
    for(int x = 0; x<strlen(str);x ++)
    {
        // printf("%c", str[x]);
        // hash = ((hash << 5) + hash) + str[x];/* hash * 33 + c */
        hash = str[x] + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

long int hash(HashTable *ht,char *str){// long?
    return sdbm(str)%ht->size;
}

void init(HashTable *ht, long int size){
    ht->size = size;
    ht->table = calloc(size,sizeof(*ht->table));
    for (long int i=0; i< size; i++){
        ht->table[i] = malloc(sizeof(*ht->table[i]));
        initLinkedList(ht->table[i]);
    }
    ht->values = 0;
}

void resizeTable(HashTable *ht, long int size){
    ht->size = size;
    ht->table = realloc(ht->table,sizeof(LinkedList)*size);
    for (long int i=0; i< size; i++){
        ht->table[i] = malloc(sizeof(*ht->table[i]));
        initLinkedList(ht->table[i]);
    }
    ht->values = 0;

}

void printTable(HashTable *ht){
    long int size = ht->size;
    for(long int x=0; x < size; x++){
        printf("\n %li: ",x);
        printLinkedList(ht->table[x]);
    }
}


void getValues(char * valArr[], HashTable *ht){
    long int size = ht->size;
    long long idx = 0;
    for(long int x=0; x < size; x++){
        if(ht->table[x]->length > 0){
            int length= ht->table[x]->length;
            // printf("--%i",length);
            char *c [length];
            values(c, ht->table[x]);
            for(int y=0; y<length; y++){
                valArr[idx] = c[y];
                idx++;
            }
        }
    }
}


void deleteTable(HashTable *ht){
    long int size = ht->size;
    // printf("\n (-)%li", size);
    for(long int x=0; x<size; x++){
        //Delete from start to end of ll
        deleteLinkedList(ht->table[x]);
        free(ht->table[x]);//possibly move this to ...

    }
    ht->size = 0;
}

void freeTable(HashTable *ht, long int size){
    for (long int i=0; i< size; i++){
        // free(ht->table[i]->start);
        // free(ht->table[i]->end);

    }
    free(ht->table);
    ht->table = NULL;
}

void resize(HashTable *ht){
    long long totalValues = ht->values;
    long long size = ht->size;  //*1110=1

    char *values[totalValues]; //= calloc(totalValues,sizeof(*values));
    getValues(values, ht);

    deleteTable(ht);
    // freeTable(ht, size);

    //double size
    resizeTable(ht, size*2);
    //set vals with new index
    for(long long x=0; x<totalValues; x++){
        add(ht, values[x]);
        // free(&values[x]);
    }
    freeValues(values, totalValues);
    // values = NULL;

}

bool in(HashTable *ht, char *word){
    long int index = hash(ht, word);
    if (!contains(ht->table[index], word))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void add(HashTable *ht, char *data){
    if (data != NULL){
        long int index = hash(ht,data);
        // printf("%f ok", ht->values/ht->size);
        if (!contains(ht->table[index], data)){
            append(ht->table[index], data);
            ht->values += 1;
            // printf("- %lld", ht->values);
        }
        // printf("%lli, %li", ht->values, ht-> size);
        while((float)ht->values/ht->size > .75){
            printf("resizing...");
            resize(ht);
        }
    }
}

// int main(void){
//     HashTable ht;
//     init(&ht,8);
//     // printTable(&ht);

//     // add(&ht, "cheese");
//     // add(&ht, "water");
//     // add(&ht, "focus");
//     // add(&ht, "one");
//     // add(&ht, "two");
//     // add(&ht, "peanut");
//     // add(&ht, "fire");
//     // add(&ht, "cereal");
//     // add(&ht, "corn");
//     // add(&ht, "nuts");
//     // add(&ht, "homegrown");
//     // add(&ht, "youtubeyoutube");
//     // add(&ht, "nuts");
//     // add(&ht, "banana dancer");
//     // add(&ht, "aerobics");
//     // add(&ht, "splits");
//     // add(&ht, "water");
//     // add(&ht, "village");
//     // add(&ht, "hokage");
//     // add(&ht, "new one");
//     char c;
//     char word[45];
//     int idx =0;
//     FILE *dict = fopen("dictionaries/large", "r");
//     if(dict == NULL) {
//       perror("Error in opening file");
//       return(-1);
//     }
//     do
//     {
//       c = (char)fgetc(dict);
//       if(c == ' ' || c == '\n' || c == '\0' || c == '\t') {
//         //wordfunction(word
//         // printf("\n %s", word);
//         add(&ht, word);
//         word[0] = 0; //Reset word
//         idx = 0;
//       } else {
//         word[idx++] = c;
//         word[idx] = 0;
//     //   printf("%c", c);
//       }
//     } while(1);
//     fclose(dict);
//     printTable(&ht);
//     long int size = ht.size;
//     deleteTable(&ht);
//     freeTable(&ht, size);//Finally.
// // }
//     return 0;
// }



 // init(&ht,8);
