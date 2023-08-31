#include "binary_trees.h"

/**
 * count_nodes - Counts the nodes inside a tree.
 * @root: Pointer to the node.
 * Return: Number of nodes.
 */
int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - Checks if a tree is complete.
 * @root: Pointer to the root node.
 * @index: Index of the node being evaluated.
 * @n: Number of tree's nodes.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(binary_tree_t *root, int index, int n)
{
	if (!root)
		return (1);

	if (index >= n)
		return (0);

	return (is_complete(root->left, index * 2 + 1, n) &
	is_complete(root->right, index * 2 + 2, n));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nod;
	binary_tree_t *root;

	if (!tree)
		return (0);

	root = (binary_tree_t *)tree;
	nod = count_nodes(root);

	return (is_complete(root, 0, nod));
}
