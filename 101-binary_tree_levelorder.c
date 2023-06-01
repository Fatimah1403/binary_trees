include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _recur_height - Determines the height of a binary tree
 * @tree: Pointer to a binary tree node.
 * Return: the height of a binary tree
 */
size_t _recur_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	left = _recur_height(tree->left);
	right = _recur_height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}


/**
 * print_level_nodes - prints the nodes of the same level.
 *
 * @tree: Pointer to the root node of the tree.
 * @level: Level of node to print, a number.
 * @func: Pointer to a callback function.
 *
 * Return: void, nothing.
 */
size_t print_level_node(const binary_tree_t *tree,
			int level, void(*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		funct(tree->n);
	else if (level > 1)
	{
		print_level_node(tree->left, level - 1, func);
		print_level_node(tree->right, level - 1, func);
	}

	return (_recur_depth(node));
}

/**
 * binary_tree_levelorder - Displays data in level-order traversal.
 *
 * @tree: Pointer to the tree root node.
 * @func: Pointer to a callback function.
 *
 * Return: Void, no return.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, index;

	if (!tree || !func)
		return;

	height = _recur_height(tree);

	for (index = 1; index <= height; index++)
		print_level_node(tree, i, func);
}
