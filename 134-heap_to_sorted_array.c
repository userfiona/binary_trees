#include "binary_trees.h"

/**
 * heapify_down - Restores the max heap property downwards.
 *
 * @root: Pointer to the root node of the heap.
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
	{
		largest = left;
	}

	if (right && right->n > largest->n)
	{
		largest = right;
	}

	if (largest != root)
	{
		swap(root, largest);
		heapify_down(largest);
	}
}
