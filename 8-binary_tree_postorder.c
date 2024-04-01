#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    /* Check if tree or func is NULL */
    if (tree == NULL || func == NULL)
        return;

    /* Traverse the left subtree */
    binary_tree_postorder(tree->left, func);

    /* Traverse the right subtree */
    binary_tree_postorder(tree->right, func);

    /* Call the function for the current node */
    func(tree->n);
}

