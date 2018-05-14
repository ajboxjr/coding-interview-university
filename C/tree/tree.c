#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

struct Tree;
struct node;

//Return whether root is empty
//Complexity:
//         Time
//All: O(1)
//        Space
//All: O(1) acess tree root
bool is_empty(Tree * tree){
  return tree->root == NULL;
}
//Set inital node data
//    Complexity
//All: O(1) travese size of pointer n
//    Space
//All: store data to node pointer.
void init_node(node ** n, int value){
  node * data = malloc(sizeof(*n));
  data->data = value;
  data->right= NULL;
  data->left = NULL;
  *n = data;
}

//Return parent node of given value
//Complexity:
//         Time
//Best: O(1) Tree empty / Worst: O(log2N) determing greater or less than per each leaf.
//        Space
//All: O(1) store parent to pointer
node * get_parent(Tree * bst, int value){
  node * sucessor = NULL;
  if(!is_empty(bst)){
    node * ptr = bst->root;
    while(ptr){
      if(value > ptr->data){
        sucessor = ptr;
        ptr = ptr->right;
      }
      else if (value < ptr->data){
        sucessor = ptr;
        ptr = ptr->left;
      }
      //Equal
      else if (value == ptr->data){
        printf("equal\n");
        return sucessor;
      }
    }
    return sucessor;
  }
  return NULL;
}

//Insert into tree
//Complexity:
//         Time
//Best: O(1) Tree empty / Worst: O(logn) determing greater or less than per each leaf.
//                        AVL: O(log2N)
//        Space
//All: O(1) store node as root or leaf
void insert(Tree * tree, int value){
  node *n;
  if(is_empty(tree)){
    init_node(&n, value);
    tree->root = n;
  }
  else {
    node * ptr = get_parent(tree, value);
    // printf("parent: %i\n", ptr->data);
    if(ptr){
      if(value < ptr->data){
        init_node(&n, value);
        ptr->left = n;
      }
      else if(value > ptr->data){
        init_node(&n, value);
        ptr->right = n;
      }
    }
    //Will not have equal condition beacuse it return parent
  }
}

//Return whether node has children
//Complexity:
//         Time
//All: O(1) traverse left and right node
//        Space
//All: O(1) acess and compare left and right
bool is_leaf(node * n){
  if(n){
    return n->left == NULL && n->right == NULL;
  }
  return false;
}

//Recursively count nodes
//Complexity:
//         Time
//Best: O(1), one node(root) / Worst: O(N), N traverse nodes
//        Space
//All: O(1), Storing total count
int count(node * n){
  // printf("a");
  int total_count = 1;
  if(n){
    if(n->left){
      total_count += count(n->left);
    }
    if (n->right){
      total_count += count(n->right);
    }
    return total_count;
  }
  return 0;
}

//Return count of all nodes in tree
//Complexity:
//         Time
//Best: O(1) empty tree / Worst: O(1) determing greater or less than per each leaf.
//        Space
//All: O(1) store node as root or leaf
int get_node_count(Tree * tree){
  if(!is_empty(tree)){
    return count(tree->root);
  }
  return 0;
}

void print_post_order(node * n){
  if(n){
    print_post_order(n->left);
    print_post_order(n->right);
    printf("%i", n->data);
  }
}

void print_pre_order(node * n){
  if(n){
    printf("%i", n->data);
    print_post_order(n->left);
    print_post_order(n->right);
  }
}

void print_inorder(node * n){
  if(n){
    print_post_order(n->left);
    printf("%i", n->data);
    print_post_order(n->right);
  }
}

//Print values order, Post, Pre
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(N) iterate through n nodes (unbalanced)
//        Space
//All: O(1) one node(root) / O(N) access and print data for each call;
void print_values(Tree * tree){
  //Post
  printf("Post Order: ");
  print_post_order(tree->root);
  // //Pre
  // printf("Pre Order: ");
  // print_pre_order(tree->root);
  // //In
  // printf("Inorder :");
  // print_inorder(tree->root);
  printf("\n");

}
//Recurively remove nodes from Tree
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(N), iterate N and remove elements
//                            AVL:(log2N), iterate and remove left and right.
//        Space
//All: O(1) one node(root) / O(N) access and print data for each call;
void delete_node(node * n){
  if(n){
    printf("deleting %i\n", n->data);
    if(n->left){
      delete_node(n->left);
    }
    if(n->right){
      delete_node(n->right);
    }
    free(n);
  }
}

//Delete and free nodes
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(N) iterate through n nodes (unbalanced)
//                            AVL: O(log2N)
//        Space
//All: O(1) store root pointer / O(N) access and delete node for each call;
void delete_tree(Tree * tree){
  if(!is_empty(tree)){
    node * ptr = tree->root;
    delete_node(tree->root);
  }
}

//Recursively get height of stem?(word)
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(h), where left height > right height vice versa
//        Space
//All: O(1) storing root count / O(N) access and store accumlator(count) for each call
int node_height(node * n){
  int left_height;
  int right_height;
  if(n){
    left_height = node_height(n->left);
    right_height = node_height(n->right);
    if (left_height > right_height){
      return 1 + left_height;
    }
    else if (left_height < right_height){
      return 1 + right_height;
    }
    //Equal height choose left or right
    else if (left_height == right_height){
      return 1 + left_height;
    }
  }
    return 0;
}

//Return the height of tree
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(h), where left height > right height vice versa
//        Space
//All: O(1) return height
int get_height(Tree * tree){
  if(!is_empty(tree)){
    return node_height(tree->root);
  }
  else {
    return 0;
  }
}

//Return node with smallest value
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(h), compare left & right to min
//        Space
//All: O(N) store left right nodes each call
node * node_min(node * n){
  // printf("bott %i", n->data);
  node * left;
  node * right;
  if(is_leaf(n)){
    return n;
  }
  else if(n->left && n->right){
    left = node_min(n->left);
    right = node_min(n->right);

    //Check base case left > right, (*does not occur in bst)
    if (left->data > right->data){
      if(n->data > right->data){
        return right;
      }
      else {
        return n;
      }
    }
    else {
      if(n->data < left->data){
        return n;
      }
      else{
        return left;
      }
    }
  }
  else if(n->left){

    left = node_min(n->left);
    if(n->data > left->data){
      return left;
    }
    else {
      return n;
    }
  }
  else if(n->right){

    right = node_min(n->right);
    if(n->data < right->data){
      return n;
    }
    else {
      return right;
    }
  }
  return n;
}

//Return node with largest value
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(h), compare left & right to min
//        Space
//All: O(N) store left right nodes each call
node * node_max(node * n){
  node * left;
  node * right;
  if(is_leaf(n)){
    return n;
  }
  else if(n->left && n->right){
    left = node_max(n->left);
    right = node_max(n->right);
    //Check base case left > right, (*does not occur in bst)
    if(left > right){
      if(n->data < left->data){
        return left;
      }
      else {
        return n;
      }
    }
    else {
      if(n->data > right->data){
        return n;
      }
      else {
        return right;
      }
    }
  }
  else if(n->left){
    left = node_max(n->left);
    if(n->data < left->data){
      return left;
    }
    else {
      return n;
    }
  }
  else if(n->right){
    right = node_max(n->right);
    if(n->data > right->data){
      return n;
    }
    else{
      return right;
    }
  }
  return n;
}

//Return min value in tree
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(h), traverse left side of tree.
//        Space
//All: O(1) point to node of tree
int get_min(Tree * tree){
  node * ptr;
  if(!is_empty(tree)){
    return node_min(tree->root)->data;
  }
  return -1;
}

//Return min value in tree
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(h), traverse right side of tree.
//        Space
//All: O(1) point to node of tree
int get_max(Tree * tree){
  node * ptr = tree->root;
  if(!is_empty(tree)){
    return node_max(tree->root)->data;
  }
  return -1;
}

//Determine whether nodes are binarily sorted
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(N), check left < main right > main
//        Space
//All: O(1) compare left &| right
bool is_binary_search_node(node *n){
  if(is_leaf(n)){
    return true;
  }
  else {
    if(n->left && n->right){
      if(n->data > n->left->data && n->data < n->right->data){
        return is_binary_search_node(n->left) && is_binary_search_node(n->right);
      }
    }
    else if(n->left){
      if (n->data > n->left->data){
          return is_binary_search_node(n->left);
      }
    }
    else if(n->right){
      if(n->data < n->right->data){
        return is_binary_search_node(n->right);
      }
    }
  }
  return false;
}

//Determine if Tree is a binary search tree
//Complexity:
//         Time
//Best: O(1) one node(root) / Worst: O(N), check left < main right > main
//        Space
//All: O(1) return binary bool
bool is_binary_search_tree(Tree * tree){
  return is_binary_search_node(tree->root);
}

//Return node with given value or NULL if none.
//Complexity:
//         Time
//All: O(1) call get parent function
//        Space
//All: O(1) return parent children
node * find_node(Tree * tree, int value){
  node * parent = get_parent(tree, value);
  if(parent){
    if(parent->data > value){
      return parent->right;
    }
    else {
      return parent->left;
    }
  }
  return NULL;
}

//Return node with given value or NULL if none.
//Complexity:
//         Time
//All: O(1) call get parent function
//        Space
//All: O(1) return parent children
void delete_value(Tree * tree, int value){
  node * parent = get_parent(tree, value);
  node * curr;
  int lorR; //O for left 1 for right
  if(parent){
    if(parent->data < value){
      curr = parent->right;
      lorR =1;
    }
    else if(parent->data > value){
      curr = parent->left;
      lorR = 0;
    }
  }
  else {
    if (value == tree->root->data){
      curr = tree->root;
    }
  }
  if(is_leaf(curr)){
    if(parent){
      if(lorR == 0){
            //parent->l/r =  NULL
        parent->left = NULL;
      }
      else {
        parent->right = NULL;
      }
    }
    free(curr);
  }
  // printf("the current is %i", curr->data );
  if(curr->right && curr->left){
    node * min = node_min(curr->right);//7
    node * minparent = get_parent(tree, min->data);//9

    //Setting parent of min it's right nodes
    if (minparent->left->data == min->data){
      minparent->left = min->right;
    }
    min->left = curr->left;
    min->right = curr->right;
    if(parent){
      if(lorR == 0){
        parent->left = min;
      }
      else {
        parent->right = min;
      }
    }
    free(curr);
  }
  //left or both
  else if(curr->left){
    if(parent){
      if(lorR == 0){
        parent->left = curr->left;
      }
      else {
        parent->right = curr->left;
      }
    }
    else {
      tree->root = curr->left;
    }
    free(curr);
    // parent->l/r = curr->left
  }
}

//Return whether value is in tree
//    Time
//All: O(1)
//    Space
//All(1): return true or false
bool is_in_tree(Tree * tree, int value){
  return find_node(tree, value) != NULL? true:false;
}

int main(void){
    Tree * bst = calloc(1, sizeof(bst));
    insert(bst, 10);
    insert(bst, 3);
    insert(bst, 1);
    insert(bst, 9);
    insert(bst, 7);
    insert(bst, 8);

    // printf("total nodes: %i\n",get_node_count(bst));
    // print_values(bst);
    // printf("height %i\n",get_height(bst));
    printf("min: %i\n",get_min(bst));
    printf("max: %i\n",get_max(bst));
    // printf("is binary tree: %s", is_binary_search_tree(bst)? "true":"false");
    // printf("deleting %i", 8);
    delete_value(bst, 10);
    printf("%d in tree: %s\n",10, is_in_tree(bst, 10)? "true": "false");
    print_values(bst);
    delete_tree(bst);
    free(bst);
}
