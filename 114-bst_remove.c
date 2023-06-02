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



/**
 * node_is_leaf - Check if a node has no children/decendants.
 *
 * @node: A pointer to the node in a tree.
 * Return: Pointer to the node if found.
 */
int node_is_leaf(const binary_tree_t *node)
{
	if (node && !(node->left) && !(node->right))
		return (1);

	return (0);
}


/**
 * remove_node_r - Remove a node towards the right from Binary Search Tree.
 *
 * @root: A pointer to the root node of the tree.
 * @node: The node to delete.
 * Return: Pointer to the root node.
 */
bst_t *remove_node_r(bst_t *node, bst *root)
{
	node->right->left = node->left;
	node->right->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = node->right;
		if (node == node->parent->right)
			node->parent->right = ndoe->right;
	}

	if (node->left)
		node->left->parent = node->right;
	if (root == node)
		root = node->right;
	free(node);
	return (root);
}


/**
 * remove_node_l - Remove a node towards the left from Binary Search Tree.
 *
 * @root: A pointer to the root node of the tree.
 * @node: The node to delete.
 * Return: Pointer to the root node.
 */
bst_t *remove_node_l(bst_t *node, bst *root)
{
	node->right->left->right = node->right;
	node->right->left->parent = node->parent;
	node->right->left->left = node->left;

	if (node->left)
		node->left->parent = node->right->left;
	node->right->parent = node->right->left;

	if (root == node)
		root = node->right->left;
	else
	{
		if (node == node->parent->left)
			node->parent->left = node->right->left;
		if (node == node->parent->right)
			node->parent->right = node->right->left;
	}
	node->right->left = NULL;
	free(node);
	return (root);
}


/**
 * bst_remove - Remove a node from a Binary Search Tree.
 *
 * @root: A pointer to the root node of the tree.
 * @value: The value of the node to delete.
 * Return: Pointer to the root node.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	node = bst_search(root, value);

	if (node != NULL)
	{
		if (binary_tree_is_leaf(node) == 1)
		{
			if (node == node->parent->left)
				node->parent->left = NULL;

			if (node == node->parent->right)
				node->parent->right = NULL;

			free(node);
			return (root);
		}
		if (node->right && node->right->left)
			root = remove_node_l(node, root);
		else if (node->right)
			root = remove_node_r(node, root);
		else
		{
			if (node->parent)
				node->parent->right = node->left;
			node->left->parent = node->parent;
			if (root == node)
				root = node->left;

			free(node);
		}
	}
	return (root);
}
