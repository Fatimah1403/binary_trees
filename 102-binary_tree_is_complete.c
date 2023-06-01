ude "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_size - Determines the size of a binary tree
 * @tree: Pointer to a binary tree node.
 * Return: the size of a binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	return (left + right + 1);
}


/**
 * is_tree_complete - Determines if a tree is complete or not.
 *
 * @tree: Pointer to the root node of the tree.
 * @i: Node index.
 * @n: Number of nodes.
 *
 * Return: 1 if tree is complete else 0.
 */
int is_tree_complete(const binary_tree_t *tree, int i, int n)
{
	if (!tree)
		return (1);

	if (i > n)
		return (0);

	return (
		tree_is_complete(tree->left, (2 * i) + 1, n) &&
		tree_is_complete(tree->right, (2 * i) + 2, n)
	);
}



/**
 * binary_tree_is_complete - Checks if a given tree is complete.
 *
 * @tree: Pointer to the tree root node.
 *
 * Return: 1 if tree is complete else 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	return (is_tree_complete(tree, 0, size));
}
