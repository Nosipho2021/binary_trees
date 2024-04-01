#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a root - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* Check if node is NULL */
	if (node == NULL)
	return (0);

	/* Check if node has no parent */
	if (node->parent == NULL)
	return (1); /* Node is a root */

	return (0); /* Node is not a root */
}

