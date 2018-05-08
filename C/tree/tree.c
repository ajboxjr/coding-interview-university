#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

bool is_empty(Tree * tree){
  return tree->root;
}
//Insert into tree
//Complexity:
//         Time
//Best: O(1) Tree empty / Worst: O(logn) determing greater or less than per each leaf.
//        Space
//All: O(1) store node as root or leaf
void insert(Tree * tree, int value){
  node * n = malloc(sizeof(* n));
  n->data = value;
  if(is_empty(tree)){
    tree->root = n;
  }
  else {
    node * item = tree->root;
    while(item){
      if (n->data > item->data){
        item = item->right;
      }
      else if (n->data == item->data){
        printf("already exists");
      }
      else {
        item = item->left;
      }
    }
  }
}

//Return count of all nodes in tree
//Complexity:
//         Time
//All: O(1) Tree empty, O(logn) determing greater or less than per each leaf.
//        Space
//All: O(1) store node as root or leaf
int get_node_count(Tree * tree){
  if(is_empty(tree)){
    return 0;
  }
  else {
    node * ptr = tree->root;
    return
  }
}
node * get_sucessor(Tree * bst, node * n){
  node * sucessor;
  if(bst->root){
    node * ptr = bst->root;
    while(ptr){
      if(n->data > ptr->data){
        sucessor = n;
        ptr = ptr->right;
      }
      else if (n->data < ptr->data){
        sucessor = n;
        ptr = ptr->left;
      }
      //Equal
      else if (n->data == ptr->data){
        break;
      }
    }
    return sucessor
  }
}

int main(void){
    Tree * bst = calloc(1, sizeof(bst));
    // printf("%i\n",bst->root->data);
    // insert(bst, 4);
    free(bst);
}
