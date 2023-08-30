#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of int
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	if (!heap || !size)
		return (NULL);

	size_t heap_size = binary_tree_size(heap);
	int *sorted_array = malloc(sizeof(int) * heap_size);

	if (!sorted_array)
		return (NULL);

	*size = heap_size;

	for (size_t i = 0; i < heap_size; ++i)
	{
		heap_t *max_node = heap_extract(&heap);
	if (!max_node)
		{
			free(sorted_array);
			return (NULL);
		}
		sorted_array[i] = max_node->n;
		free(max_node);
	}

	return (sorted_array); No parentheses required
}
