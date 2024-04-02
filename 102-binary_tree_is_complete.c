#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is complete, 1.
 *         Otherwise, 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	size_t height = binary_tree_height(tree);
	int flag = 0;
	size_t i;

	for (i = 0; i < height; i++)
	{
	if (tree)
	{
	if (flag)
	{
	if (tree->left || tree->right)
	return (0);
	}
	else
	{
	if (tree->left && tree->right)
	{
		tree = tree->left;
	}
	else if (tree->left || tree->right)
	{
	flag = 1;
	if (tree->left)
	tree = tree->left;
	else
	tree = tree->right;
	}
	else
	{
	flag = 1;
	}
	}
	}
	}

	return (1);
}

