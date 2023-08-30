#include "binary_trees.h"

/**
 * find_successor - Finds the next in-order successor of a node
 * @node: Node for which to find the successor
 * Return: Value of the successor node
 */
int find_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = find_successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * replace_with_successor - Replaces a node's value with its in-order successor
 * @root: Node to be replaced
 * Return: Value of the successor node
 */
int replace_with_successor(bst_t *root)
{
	int new_value = 0;

	new_value = find_successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 * remove_node_type - Removes a node based on its number of children
 * @root: Node to remove
 * Return: 0 if it has no children or other value if it has
 */
int remove_node_type(bst_t *root)
{
	// Implementation remains unchanged
}

/**
 * bst_remove - Removes a node from a BST tree
 * @root: Root of the tree
 * @value: Node with this value to remove
 * Return: The tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return root;
}
