#ifndef TREE_H
#define TREE_H
#include <stdbool.h>

struct node;
typedef struct node {
  int data;
  struct node * left;
  struct node * right;
} node;
typedef struct Tree {
  node * root;
} Tree;

node * get_parent(Tree * bst, int value);

bool is_leaf(node * n);

void print_inorder(node * n);

void print_pre_order(node * n);

void print_post_order(node * n);

bool is_empty(Tree * tree);

void insert(Tree * tree, int value);

int count(node * n);

int get_node_count(Tree * tree);

void print_values(Tree * tree);

node * find_node(Tree * tree, int value);

void delete_node(node * n);

void delete_tree(Tree * tree);

bool is_in_tree(Tree * tree , int value);

int node_height(node * n);

int get_height(Tree * tree);

node * node_max(node * n);

node * node_min(node * n);

int get_min(Tree * tree);

int  get_max(Tree * tree);

bool is_binary_search_node(node *n);

bool is_binary_search_tree(Tree * tree);

void delete_value(Tree * tree, int value);

int get_sucessor(Tree * tree);

#endif
