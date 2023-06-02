#include "binary_trees.h"

/**
 * node_is_leaf - Check if a node is leaf
 *
 * @node: pointer to given node
 * Return: 1 if true, 0 if false.
 */
int node_is_leaf(const binary_tree_t *node)
{
	int leaf = 0;

	if (node && !(node->left) && !(node->right))
		leaf = 1;
	return (leaf);
}

/**
 * check_parent - Check if a node is higher or lower that grand parent node.
 * @node: Pointer to node.
 * Return: 1 if true, 0 i false.
 */
int check_parent(const binary_tree_t *node)
{
	const binary_tree_t *parent, *grand_parent;

	if (!node || !(node->parent) || !(node->parent->parent))
		return (1);

	parent = node->parent;
	grand_parent = node->parent;

	while (parent && grand_parent)
	{
		if (parent->n < grand_parent->n &&
				node->n >= grand_parent->n)
			return (0);

		if (parent->n > grand_parent->n &&
				node->n <= grand_parent->n)
			return (0);

		parent = parent->parent;
		grand_parent = parent->parent;
	}

	return (1);
}

/**
 * check_is_bst - Checks if a binary tree is a Binary search tree.
 *
 * @tree: pointer to the tree root node.
 * Return: 1 if true else 0.
 */
int check_is_bst(const binary_tree_t *tree)
{
	const check_left, check_right;

	if (!tree)
		return (1);

	if (binary_tree_is_leaf(tree))
		return (1);

	if (tree->left && tree->left->n >= tree->n)
		return (0);

	if (tree->right && tree->right->n <= tree->n)
		return (0);

	check_left = check_parent(tree->left);
	check_right = check_parent(tree->right);

	if (!check_left || !check_right)
		return (0);

	return (check_is_bst(tree->left) && check_is_bst(tree->right));
}


/**
 * binary_tree_is_bst - checks if a tree is BST
 *
 * @tree: A pointer to a binary tree root node.
 * Return: 1 if true, 0 if false.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_is_bst(tree));
}
