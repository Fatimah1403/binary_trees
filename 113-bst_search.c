#include "binary_trees.h"

/**
 * bst_search - Search for a value in a Binary Search Tree.
 *
 * @tree: A pointer to the root node of the tree.
 * @value: The node value to search.
 * Return: Pointer to the node if found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree && value < tree->n)
		return (bst_search(tree->left, value));

	if (tree && value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}
