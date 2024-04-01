#include "binary_trees.h"

/**
 * inorder_successor - Returns the minimum value node in a BST.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value node in the BST.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
	root = root->left;
	return root;
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	if (root == NULL)
	return NULL;

	if (node->n < root->n)
	root->left = bst_delete(root->left, node);
	else if (node->n > root->n)
		root->right = bst_delete(root->right, node);
	else
	{
	if (root->left == NULL)
	{
	bst_t *temp = root->right;
	free(root);
	return temp;
	}
	else if (root->right == NULL)
	{
	bst_t *temp = root->left;
	free(root);
	return temp
	}	
	bst_t *temp = inorder_successor(root->right);
	root->n = temp->n;
	root->right = bst_delete(root->right, temp);
	}
	return root;
}

/**
 * bst_remove_recursive - Recursively removes a node with the given value from a BST.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to remove.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the new root node after removal.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (root == NULL)
	return NULL;

	if (value < root->n)
	root->left = bst_remove_recursive(root->left, node, value);
	else if (value > root->n)
	root->right = bst_remove_recursive(root->right, node, value);
	else
	{
	if (root == node)
	{
	bst_t *new_root = bst_delete(root, node)
		    retu

