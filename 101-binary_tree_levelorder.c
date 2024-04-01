#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, your function must return 0, else return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
	tree = tree->parent;
	depth++;
	}
	return (depth);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	return;

	size_t height = binary_tree_depth(tree);
	size_t i;
	binary_tree_t **level_nodes = malloc(sizeof(binary_tree_t *) * (1 << height));

	if (!level_nodes)
	return;

	for (i = 0; i < (1 << height); i++)
	level_nodes[i] = NULL;

	level_nodes[0] = (binary_tree_t *)tree;

	for (i = 0; i < (1 << height); i++)
	{
	if (level_nodes[i])
	{

		func(level_nodes[i]->n);
	if (level_nodes[i]->left)
	level_nodes[2 * i + 1] = level_nodes[i]->left;
	if (level_nodes[i]->right)
	level_nodes[2 * i + 2] = level_nodes[i]->right;
	}
	}

	free(level_nodes);
}

