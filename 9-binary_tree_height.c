#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    /* Check if tree is NULL */
    if (tree == NULL)
        return (0);

    /* Get the height of the left subtree */
    left_height = binary_tree_height(tree->left);

    /* Get the height of the right subtree */
    right_height = binary_tree_height(tree->right);

    /* Return the maximum height of the subtrees + 1 (to account for the current node) */
    return (1 + MAX(left_height, right_height));
}

