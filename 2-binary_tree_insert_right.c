#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 * Return: Pointer to the new node, NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (!parent)
		return (NULL);

	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (!new_node)
		return (NULL);

	new_node->right = parent->right;
	parent->right = new_node;

	if (new_node->right)
		new_node->right->parent = new_node;

	return (new_node);
}
