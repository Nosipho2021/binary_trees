#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: Length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[6];
    int width, left, right, is_left, i;

    if (!tree)
        return 0;

    sprintf(b, "(%03d)", tree->n);
    width = strlen(b);

    left = print_t(tree->left, offset, depth + 1, s);
    right = print_t(tree->right, offset + left + width, depth + 1, s);

    is_left = (tree->parent && tree == tree->parent->left);
    
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }

    return left + width + right;
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    int height, i, j;

    if (!tree)
        return;

    height = binary_tree_height(tree);
    s = malloc(sizeof(char *) * (height + 1));
    if (!s)
        return;
    for (i = 0; i < height + 1; i++)
    {
        s[i] = malloc(sizeof(char) * 255);
        if (!s[i])
            return;
        memset(s[i], 32, 255);
    }

    print_t(tree, 0, 0, s);

    for (i = 0; i < height + 1; i++)
    {
        for (j = 254; j > 1; --j)
	{
	if (s[i][j] != ' ')
	break;
	s[i][j] = '\0';
	}
	printf("%s\n", s[i]);
	free(s[i]);
	}
	free(s);
}
