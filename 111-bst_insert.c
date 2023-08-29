#include "binary_trees.h"

/**
 * bst_insert_recursion - recursively traverses a Binary Search Tree to insert
 * a new value
 *
 * @tree: binary tree node
 * @value: integer to insert in new node
 * Return: pointer to new node, or NULL on failure or value found already
 * found in tree
 */
bst_t *bst_insert_recursion(bst_t *tree, int value)
{
    bst_t *new = NULL;

    if (tree == NULL)
    {
        new = binary_tree_node(tree, value);
        return (new);
    }

    if (tree->n > value)
    {
        tree->left = bst_insert_recursion(tree->left, value);
    }
    else if (tree->n < value)
    {
        tree->right = bst_insert_recursion(tree->right, value);
    }

    return (tree);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: binary tree node passed by reference
 * @value: integer to insert in new node
 * Return: pointer to new node, or NULL on failure or value found already
 * found in tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    return (bst_insert_recursion(*tree, value));
}
