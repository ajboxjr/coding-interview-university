#ifndef MERGE_SORT_H
#define MERGE_SORT_H
void merge_sort_ll(LinkedList * ll);
void split(node * ll, node **left, node ** right);
void merge(node ** result, node *left, node *right);
node * merge_sort(node * ll);

#endif
