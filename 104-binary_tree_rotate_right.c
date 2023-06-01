#include "binary_trees.h"


/**
 * binary_tree_rotate_right - Rotatea binary tree the right.
 *
 * @tree: Pointer to the tree root node.
 *
 * Return: Pointer to new root node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || tree->left == NULL)
		return (tree);

	new_root = tree->left;

	if (new_root->right)
	{
		tree->left = new_root->right;
		new_root->right->parent = tree;
	}
	else
	{
		tree->left = NULL;
	}


	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
