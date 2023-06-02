#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node
 * Return: the size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}

/**
 * is_tree_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node
 * @i: A node index.
 * @num_of_nodes: Number of nodes.
 * Return: 1 if complete else 0.
 */
int is_tree_complete(const binary_tree_t *tree, int i, int num_of_nodes)
{
	size_t left_check, right_check;

	if (tree == NULL)
		return (0);

	if (i >= num_of_nodes)
		return (0);

	left_check = is_tree_complete(tree->left, (2 * i) + 1, num_of_nodes);
	right_check = is_tree_complete(tree->right, (2 * i) + 1, num_of_nodes);

	return (left_check && right_check);
}

/**
 * run_is_tree_complete - Runs the is_tree_complete function.
 *
 * @tree: Pointer to the root node
 * Return: result of is_tree_complete_function.
 */
int run_is_tree_complete(const binary_tree_t *tree)
{
	size_t num_of_nodes;

	if (tree == NULL)
		return (0);

	num_of_nodes = binary_tree_size(tree);

	return (is_tree_complete(tree, 0, num_of_nodes));
}

/**
 * check_parent - Check node value greater than the value of it children
 *
 * @tree: Pointer to the root node
 * Return: 1 if true, 0 if false.
 */
int check_parent(const binary_tree_t *tree)
{
	int check_left_nodes, check_right_nodes;

	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	check_left_node = check_parent(tree->left);
	check_right_node = check_parent(tree->right);

	return (check_left_node && check_right_node);
}

/**
 * binary_tree_is_heap - Check if an input tree is a Max Binary Heap.
 *
 * @tree: Pointer to the root node
 * Return: 1 if true, 0 if false.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t left_c, right_size;

	if (!run_is_tree_complete(tree))
		return (0);

	left_check = check_parent(tree->left);
	right_check = check_parent(tree->right);

	return (left_check && right_check);
}

