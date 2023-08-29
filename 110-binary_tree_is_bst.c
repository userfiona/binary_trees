#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - recursive helper function to check_if_BST
 * @tree: tree to check for BST
 * @min: minimum value allowed for the subtree
 * @max: maximum value allowed for the subtree
 * Return: 1 if `tree` is valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: tree to check
 * Return: 1 if `tree` is valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
