#include "binary_trees.h"

/**
 * binary_tree_nodes - To count at least a child of a binary tree.
 * @tree: Pointer to a binary tree instance.
 *
 * Return: the number of leaves in the tree.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	return (0);
}
