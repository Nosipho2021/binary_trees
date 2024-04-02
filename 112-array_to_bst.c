#include "binary_trees.h"

/**
 * sorted_array_to_bst - Builds a binary search tree from a sorted array.
 * @array: A pointer to the first element of the sorted array.
 * @start: The starting index of the array.
 * @end: The ending index of the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *sorted_array_to_bst(int *array, int start, int end)
{
	if (start > end)
	return (NULL);

	int mid = (start + end) / 2;
	bst_t *root = binary_tree_node(NULL, array[mid]);

	if (root == NULL)
	return (NULL);

	root->left = sorted_array_to_bst(array, start, mid - 1);
	root->right = sorted_array_to_bst(array, mid + 1, end);

	return (root);
}

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
	return (NULL);

	/*Build BST from sorted array*/
	return (sorted_array_to_bst(array, 0, size - 1));
}

