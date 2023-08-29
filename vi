#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return NULL;

	return sata_helper(array, 0, size - 1);
}

/**
 * sata_helper - helper that recursively builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @lo: lower bound index
 * @hi: upper bound index
 * Return: pointer to the root node of the created AVL tree
 */
avl_t *sata_helper(int *array, size_t lo, size_t hi)
{
	if (lo > hi)
		return NULL;

	size_t middle = (lo + hi) / 2;
	avl_t *new_node = binary_tree_node(NULL, array[middle]);

	if (!new_node)
		return NULL;

	new_node->left = sata_helper(array, lo, middle - 1);
	new_node->right = sata_helper(array, middle + 1, hi);

	return new_node;
}
