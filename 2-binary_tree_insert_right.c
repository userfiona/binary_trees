#include "binary_trees.h"
/**
 * binary_tree_insert_right - function that inserts a node as the right-child of another node
 * @param pointer to parent node
 * @param value inside each node
 * @return node address
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return NULL;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return NULL;

	node->n = value;
	node->parent = parent;
	node->right = parent->right;
	parent->right = node;

	if (node->right)
		node->right->parent = node;

	return(node);	
}
