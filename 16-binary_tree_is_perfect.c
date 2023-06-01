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
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	/* find the height of left, right subtree. */
	if (tree->left)
	{
		left_height = 1 + binary_tree_height(tree->left);
	}
	if (tree->right)
	{
		right_height = 1 + binary_tree_height(tree->right);

	}
	return (left_height > right_height ? left_height : right_height);
}

/**
 * _pow - Emulate pow function by recursion
 * @x: Base
 * @y: Exponent
 *
 * Return: Power on the Base and exponent.
 */
int _pow(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	return (x * _pow(x, y - 1));
}

/**
 * binary_tree_leaves - Count the leaves in a binary tree.
 *
 * @tree: pointer to a binary tree instance.
 *
 * Return: Number of leaves in the binary tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}


/**
 * binary_tree_is_perfect - To check if a binary tree is perfect.
 *
 * @tree: Pointer to a binary tree instance
 *
 * Return: 1 if perfect or 0 if not.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, leaves;

	if (!tree)
		return (0);

	height = (int)binary_tree_height(tree);
	leaves = (int)binary_tree_leaves(tree);

	if (_pow(2, height) == leaves)
		return (1);
	return (0);
}
