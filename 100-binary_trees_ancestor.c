#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _recur_depth - Determines the depth of a node in a binary tree
 * @tree: Pointer to a binary tree node.
 * Return: the depth of a node in binary tree
 */
size_t _recur_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (-1);
	return (_recur_depth(tree->parent) + 1);
}


/**
 * binary_tree_depth - measures the depth of a binary tree recursively.
 * @node: pointer to the root node of the tree.
 *
 * Return: depth of the node, 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return (_recur_depth(node));
}

/**
 * binary_trees_ancestor - Determine the lowest common ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor
 */
binary_tree_t *binary_tree_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	if (first_depth >  second_depth)
		return (binary_trees_ancestor(first->parent, second));

	if (binary_tree_depth(first) < binary_tree_depth(second))
		return (binary_trees_ancestor(first, second->parent));

	return (binary_trees_ancestor(first->parent, second->parent));
}
