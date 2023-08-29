#include "binary_trees.h"

/**
 * tree_is_perfect - Checks if a tree is perfect.
 * @tree: Pointer to the root node of the tree.
 * Return: The level of height if perfect, otherwise 0.
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	int l = tree_is_perfect(tree->left);
	int r = tree_is_perfect(tree->right);

	return ((l != 0 && r != 0) && (l == r) ? l + 1 : 0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (tree_is_perfect(tree) != 0);
}
