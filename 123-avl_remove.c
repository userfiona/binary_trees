#include "binary_trees.h"

/**
 * avl_remove - function to remove a node from an AVL tree
 * @root: pointer to the root node of the tree
 * @value: value to remove from the tree
 * Return: pointer to the new root node after removal and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (!root)
        return NULL;

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if (!root->left || !root->right)
        {
            avl_t *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        avl_t *temp = root->right;
        while (temp->left)
            temp = temp->left;
        root->n = temp->n;
        root->right = avl_remove(root->right, temp->n);
    }

    if (!root)
        return NULL;

    root = balance_tree(root);

    return root;
}
