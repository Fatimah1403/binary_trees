#include "binary_trees.h"

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
 * binary_tree_balance - To determine the balance factor of a binary tree.
 * @tree: Pointer to a binary tree instance.
 *
 * Return: the number of leaves in the tree.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = (tree->left) ? (int)binary_tree_height(tree->left) : -1;
	right_height = (tree->right) ? (int)binary_tree_height(tree->right) : -1;

	return (left_height - right_height);
}
