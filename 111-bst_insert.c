#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		if (!new)
			return (NULL);
		*tree = new;
		return (new);
	}

	if (value < (*tree)->n)
		return (bst_insert(&((*tree)->left), value));
	else if (value > (*tree)->n)
		return (bst_insert(&((*tree)->right), value));

	return (NULL);
}
