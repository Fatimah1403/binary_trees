#include "binary_trees.h"

/**
 * binary_tree_sibling - To determine if a binary tree is full.
 * @node: Pointer to a node in a binary tree instance.
 *
 * Return: Pointer to sibling or NULL.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{

	if (!node || !(node->parent))
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	if (node->parent->right == node)
		return (node->parent->left);
	return (NULL);
}
