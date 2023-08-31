#include "binary_trees.h"

/**
 * binary_tree_is_heap - function to check if a binary tree is a valid Max Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
