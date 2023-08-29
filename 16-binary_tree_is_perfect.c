#include "binary_trees.h"

/**
 * tree_is_perfect - Recursively checks if a tree is perfect.
 * @tree: Pointer to the root node of the tree.
 * @height: Height of the current level (used for checking perfectness).
 * Return: Height of the tree if perfect, or -1 if not perfect.
 */
int tree_is_perfect(const binary_tree_t *tree, int height)
{
	int left_height, right_height;
	
	if (!tree)
		return (height);

	if (!tree->left && !tree->right)
		return (height + 1);

	left_height = tree_is_perfect(tree->left, height + 1);
	right_height = tree_is_perfect(tree->right, height + 1);

	if (left_height == -1 || right_height == -1 || left_height != right_height)
		return (-1);

	return (left_height);
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
	return (tree_is_perfect(tree, 0) != -1);
}
