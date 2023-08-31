#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: root of the tree to evaluate
 * @value: value to find
 * Return: pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);
	else if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
