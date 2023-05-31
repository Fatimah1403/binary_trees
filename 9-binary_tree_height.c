#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: nothing.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	left_height = 0;
	right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		/* find the height odf left, right subtree. */
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);

		return (max(left_height, right_height) + 1);

	}


}
