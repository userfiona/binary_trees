#include "binary_trees.h"

/**
 * heapify_up - corrects the Max Heap property by moving the node up
 * @node: pointer to the node to be moved up
 */
void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		int temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = binary_tree_node(NULL, value);

	if (!new)
		return (NULL);

	if (!(*root))
	{
		*root = new;
		return (new);
	}

	if ((*root)->left == NULL)
		(*root)->left = new;
	else if ((*root)->right == NULL)
		(*root)->right = new;
	else if (binary_tree_nodes((*root)->left) <=
			 binary_tree_nodes((*root)->right))
		(*root)->left = new;
	else
		(*root)->right = new;

	new->parent = *root;

	heapify_up(new);

	return (new);
}
