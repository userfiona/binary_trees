#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left.
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: Pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || !tree->right)
		return (NULL);

	pivot = tree->right;
	tree->right = pivot->left;
	if (pivot->left)
		pivot->left->parent = tree;

	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;

	
