#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    /* Check if tree is NULL */
    if (tree == NULL)
        return (0);

    /* If the current node is a leaf, return 1 */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* Recursively count the leaves in the left and right subtrees */
    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}

