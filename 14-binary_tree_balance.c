#include "binary_trees.h"

/**
 * binary_tree_height_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Height of the tree.
 *         If tree is NULL, return 0.
 */
size_t binary_tree_height_balance(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
		return (0);

	h_left = tree->left ? 1 + binary_tree_height_balance(tree->left) : 0;
	h_right = tree->right ? 1 + binary_tree_height_balance(tree->right) : 0;

	return ((h_left > h_right) ? h_left : h_right);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 * Return: Balance factor.
 *         If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
		return (0);

	h_left = tree->left ? 1 + binary_tree_height_balance(tree->left) : 0;
	h_right = tree->right ? 1 + binary_tree_height_balance(tree->right) : 0;

	return (h_left - h_right);
}
