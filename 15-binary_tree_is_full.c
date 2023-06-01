#include "binary_trees.h"

/**
 * binary_tree_is_full - To determine if a binary tree is full.
 * @tree: Pointer to a binary tree instance.
 *
 * Return: the number of leaves in the tree.
 */

size_t binary_tree_is_full(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);

	if (tree->left && tree->right)

		return (
			binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right)
		);

	return (0);
}
