#include "binary_trees.h"

/**
 * binary_tree_insert_left - Add a node to the left of the parent
 * @parent: Parent node to insert the new node to the left
 * @value: Value of the new node
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (!parent)
		return (NULL);

	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (!new_node)
		return (NULL);

	if (parent->left)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}

	parent->left = new_node;
	return (new_node);
}
