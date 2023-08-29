#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: Pointer to root
 */

/* Helper function to recursively insert elements and maintain AVL balance */
avl_t *insert_rec(avl_t **root, int value);

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		insert_rec(&root, array[i]);

	return (root);
}

/* Helper function to insert a value into an AVL tree */
avl_t *insert_rec(avl_t **root, int value)
{
	if (*root == NULL)
		return (binary_tree_node(NULL, value));

	if (value < (*root)->n)
		(*root)->left = insert_rec(&((*root)->left), value);
	else if (value > (*root)->n)
		(*root)->right = insert_rec(&((*root)->right), value);

	(*root) = balance_tree(*root);

	return (*root);
}
