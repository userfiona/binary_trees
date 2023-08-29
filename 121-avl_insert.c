#include "binary_trees.h"

/**
 * avl_insert - inserts a value into an AVL tree.
 * @tree: double pointer to the root node of the AVL tree to insert into.
 * @value: value to store in the node to be inserted
 * Return: inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	return (r_insert_node(tree, NULL, value));
}

/**
 * r_insert_node - node value insertion in an AVL.
 * @tree: double pointer of root node of the AVL tree struct.
 * @parent: parent node of AVL.
 * @nval: insertion value of the AVL.
 * Return: pointer to the new root after insertion otherwise NULL
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, int nval)
{
	int bval;
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		new = binary_tree_node(parent, nval);
		*tree = new;
		return (new);
	}

	if ((*tree)->n > nval)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}

	bval = binary_tree_balance(*tree);

	if (bval > 1 && (*tree)->left->n > nval)
		return (binary_tree_rotate_right(*tree));

	if (bval > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	if (bval < -1 && (*tree)->right->n < nval)
		return (binary_tree_rotate_left(*tree));

	if (bval < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}`
