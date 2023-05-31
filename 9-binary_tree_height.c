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
		return (0);

	/* find the height of left, right subtree. */
	if (tree->left)
	{
		left_height = binary_tree_height(tree->left);
		left_height += 1;
	}
	if (tree->right)
	{
		right_height = binary_tree_height(tree->right);
		right_height += 1;

	}
	return (right_height > left_height ? left_height : right_height);


}
