#include "binary_trees.h"

/**
 * successor - Gets the next successor, which is the minimum node in the right subtree.
 * @node: Tree to check.
 * Return: The minimum value of this tree.
 */
int successor(bst_t *node)
{
	if (node->left)
		return successor(node->left);
	return node->n;
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: Value to remove in the tree.
 * Return: Pointer to the new root node of the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return NULL;

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			bst_t *temp = root->right;
			free(root);
			return temp;
		}
		else if (!root->right)
		{
			bst_t *temp = root->left;
			free(root);
			return temp;
		}

		root->n = successor(root->right);
		root->right = bst_remove(root->right, root->n);
	}

	return root;
}
