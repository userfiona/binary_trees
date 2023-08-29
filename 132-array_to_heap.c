#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created Binary Heap, or NULL on failure
 */

/* Helper function to build the Max Binary Heap from an array */
void heapify_array(heap_t *node);

heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *root = NULL;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		root = heap_insert(&root, array[i]);
		if (!root)
			return (NULL);
	}

	heapify_array(root);

	return (root);
}

/* Helper function to heapify the entire tree */
void heapify_array(heap_t *node)
{
	if (!node)
		return;

	heapify_array(node->left);
	heapify_array(node->right);
	heapify_down(node);
}
