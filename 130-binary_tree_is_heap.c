#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root = ...;
	int is_heap = binary_tree_is_heap(root);

	if (is_heap)
	{
		printf("The tree is a valid Max Binary Heap.\n");
	}
	else
	{
		printf("The tree is not a valid Max Binary Heap.\n");
	}

	return (0);
}
