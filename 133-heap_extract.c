#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t heap_size, i;

	if (!heap || !size)
		return (NULL);

	heap_size = binary_tree_size(heap);
	sorted_array = malloc(sizeof(int) * heap_size);
	if (!sorted_array)
		return (NULL);

	for (i = 0; i < heap_size; i++)
	{
		sorted_array[i] = heap->n;
		heap->n = INT_MAX;
		heap = perc_down(heap);
	}

	*size = heap_size;

	return (sorted_array);
}
