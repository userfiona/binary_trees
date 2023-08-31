#include "binary_trees.h"

/**
 * heap_extract - Extracts the root value from a Binary Max Heap.
 *
 * @root: Double pointer to the root node of the heap.
 * Return: Value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);

	int extracted_value = (*root)->n;

	return (extracted_value);
}
