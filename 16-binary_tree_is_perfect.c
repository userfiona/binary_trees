#include "binary_trees.h"

/**
 * tree_is_perfect - Checks if a tree is perfect.
 * @tree: Pointer to the root node of the tree.
 * Return: Height of the tree if perfect, or -1 if not perfect.
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (-1);

	if (tree->left && tree->right)
	{
		l = tree_is_perfect(tree->left);
		r = tree_is_perfect(tree->right);
		if (l == r && l != -1 && r != -1)
			return (l + 1);
		return (-1);

	}
	else if (!tree->left && !tree->right)
	{
		return (0);
	}
	return (-1);
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

	return (tree_is_perfect(tree) != -1);
}
