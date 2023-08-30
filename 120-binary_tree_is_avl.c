#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - Recursively checks if a binary tree is an AVL Tree
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
    int path_l, path_r;

    if (!tree)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    path_l = binary_tree_height(tree->left);
    path_r = binary_tree_height(tree->right);

    if (abs(path_l - path_r) > 1)
        return (0);

    return (btia_helper(tree->left, min, tree->n) &&
            btia_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Tree to measure the height of
 *
 * Return: Height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l = 0;
    size_t height_r = 0;

    if (!tree)
        return (0);

    height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
    return (height_l > height_r ? height_l : height_r);
} 
