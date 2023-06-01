#include "binary_trees.h"

/**
 * binary_tree_sibling - To determine if a binary tree is full.
 * @node: Pointer to a node in a binary tree instance.
 *
 * Return: Pointer to sibling or NULL.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{

	if (!tree || !(node->parent))
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	return (node->parent->left);
}
