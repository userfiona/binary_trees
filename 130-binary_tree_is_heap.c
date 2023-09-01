#include <stdio.h>
#include "binary_trees.h"

int main(void)
{
	/* Create your binary tree or use an existing one */

	binary_tree_t *root = ...;

	int is_heap = binary_tree_is_heap(root);

	if (is_heap)
	{
		printf("The tree is a valid Max Heap.\n");
	}
	else
	{
		printf("The tree is not a valid Max Heap.\n");
	}

	return (0);
}
