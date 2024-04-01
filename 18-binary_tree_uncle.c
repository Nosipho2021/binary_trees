#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: If node is NULL or there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    /* Check if node or its parent is NULL */
    if (node == NULL || node->parent == NULL)
        return (NULL);

    /* If node is the left child, return the right child (if exists) */
    if (node->parent->left == node)
        return (node->parent->right);

    /* If node is the right child, return the left child (if exists) */
    if (node->parent->right == node)
        return (node->parent->left);

    /* If node is neither left nor right child, return NULL */
    return (NULL);
}

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: If node is NULL or has no uncle, NULL.
 *         Otherwise, a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    binary_tree_t *parent_sibling;

    /* Check if node is NULL or has no parent */
    if (node == NULL || node->parent == NULL)
        return (NULL);

    /* Find the sibling of the parent of the node */
    parent_sibling = binary_tree_sibling(node->parent);

    /* If parent has no sibling, node has no uncle */
    if (parent_sibling == NULL)
        return (NULL);

    /* Return the sibling of the parent of the node (uncle) */
    return (parent_sibling);
}

