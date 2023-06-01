#include "binary_trees.h"

/**
 * binary_tree_nodes - To count at least a child of a binary tree.
 * @tree: Pointer to a binary tree instance.
 *
 * Return: the number of leaves in the tree.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t child = 0;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		child += 1;
	if (tree->left)
		child += binary_tree_nodes(tree->left);
	if (tree->right)
		child += binary_tree_nodes(tree->right);
	return (child);
}
