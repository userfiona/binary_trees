#include "binary_trees.h"

/**
 * bst_t *bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return *tree;
	}

	if (value < (*tree)->n)
		return bst_insert(&((*tree)->left), value);
	else if (value > (*tree)->n)
		return bst_insert(&((*tree)->right), value);

	return NULL;
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

		bst_t *temp = binary_tree_min_value_node(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return root;
}

/**
 * binary_tree_min_value_node - Finds the node with the minimum value in a BST.
 * @node: Pointer to the root node of the BST.
 * Return: Pointer to the node with the minimum value.
 */
bst_t *binary_tree_min_value_node(bst_t *node)
{
	bst_t *current = node;
	while (current && current->left)
		current = current->left;
	return current;
}
