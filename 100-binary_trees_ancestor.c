#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
	if (!first || !second)
		return NULL;

	size_t depth_f = binary_tree_depth(first);
	size_t depth_s = binary_tree_depth(second);

	while (depth_f > depth_s)
	{
		first = first->parent;
		depth_f--;
	}

	while (depth_s > depth_f)
	{
		second = second->parent;
		depth_s--;
	}

	while (first && second)
	{
		if (first == second)
			return (binary_tree_t *)first;

		first = first->parent;
		second = second->parent;
	}

	return NULL;
}
