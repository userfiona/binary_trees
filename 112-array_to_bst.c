#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 *
 * @array: Array of integers, may be unsorted and have repeating values.
 * @size: Amount of array members.
 * Return: Pointer to head of new BST constructed from array, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	if (!array || size == 0)
		return NULL;

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&tree, array[i]) == NULL)
		{
			for (j = 0; j < size && array[j] != array[i]; j++)
			{
				// Empty loop body, just iterate to find if the value exists
			}

			if (j == i)
				return NULL;
		}
	}

	return tree;
}
