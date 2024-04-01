#include "binary_trees.h"
#include "limits.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;
    
    size_t left_height = height(tree->left);
    size_t right_height = height(tree->right);
    
    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The minimum valid value of a node in the tree.
 * @hi: The maximum valid value of a node in the tree.
 *
 * Return: If tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
    if (tree == NULL)
        return 1;

    if (tree->n < lo || tree->n > hi)
        return 0;

    size_t left_height = height(tree->left);
    size_t right_height = height(tree->right);

    if (abs((int)left_height - (int)right_height) > 1)
        return 0;

    return is_avl_helper(tree->left, lo, tree->n - 1) &&
           is_avl_helper(tree->right, tree->n + 1, hi);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not an AVL tree, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return is_avl_helper(tree, INT_MIN, INT_MAX);
}

