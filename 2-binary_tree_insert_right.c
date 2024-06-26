#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a right-child, the new node
 *              takes its place and the old right-child is set as
 *              the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if parent is NULL */
	if (parent == NULL)
	return (NULL);

	/* Allocate memory for new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	return (NULL);

	/* Assign values to the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;

	/* Inserting as right child */
	new_node->right = parent->right;
	if (new_node->right != NULL)
	new_node->right->parent = new_node;
	parent->right = new_node;

	return (new_node);
}
