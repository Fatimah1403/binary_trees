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

	if (node == node->parent->left)
		return (node->parent->right);

	return (node->parent->left);
}

/**
 * binary_tree_uncle - Function to find the uncle of a node.
 *
 * @node: Pointer to a node in the binary tree instance.
 *
 * Return: Pointer to uncle or NULL.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
