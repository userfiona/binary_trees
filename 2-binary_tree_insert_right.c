#include "binary_trees.h"
  2 /**
  3  * binary_tree_insert_right - function that inserts a node as the right-child of another node
  4  * @param pointer to parent node
  5  * @param value inside each node
  6  * @return node address
  7  */
  8 binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
  9 {
 10         binary_tree_t *node;
 11 
 12         if (!parent)
 13                 return NULL;
 14 
 15         node = malloc(sizeof(binary_tree_t));
 16         if (!node)
 17                 return NULL;
 18 
 19         node->n = value;
 20         node->parent = parent;
 21         node->right = parent->right;
 22         parent->right = node;
 23 
 24         if (node->right)
 25                 node->right->parent = node;
 26 
 27         return(node);
