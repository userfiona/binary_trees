#include "binary_trees.h"

/**
 * bst_insert_recursion - Recursively traverses a Binary Search Tree to insert
 * a new value.
 *
 * @tree: Binary tree node.
 * @value: Integer to insert in the new node.
 * Return: Pointer to the new node, or NULL on failure or if value is already
 * found in the tree.
 */
bst_t *bst_insert_recursion(bst_t *tree, int value)
{
	bst_t *new = NULL;

	if (tree == NULL)
	{
		new = binary_tree_node(tree, value);
		return (new);
	}

	if (tree->n > value)
	{
		tree->left = bst_insert_recursion(tree->left, value);
	}
	else if (tree->n < value)
	{
		tree->right = bst_insert_recursion(tree->right, value);
	}

	return (tree);
}

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 *
 * @tree: Binary tree node passed by reference.
 * @value: Integer to insert in the new node.
 * Return: Pointer to the new node, or NULL on failure or if value is already
 * found in the tree.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (bst_insert_recursion(*tree, value));
}
