#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    /* Check if tree is NULL */
    if (tree == NULL)
        return (0);

    /* Recursively calculate the size of the left and right subtrees
       and add 1 to account for the current node */
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
