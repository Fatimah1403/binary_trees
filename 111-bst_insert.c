#include "binary_trees.h"

/**
 * insert_node - Inserts a node to binary tree
 *
 * @tree: pointer to root node of the binary tree.
 * @value: value of the new node to be inserted.
 * Return: pointer to the inserted (new) node.
 */
bst_t *insert_node(bst_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			return (insert_node(&((*tree)->left), value));
		}
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			return (insert_node(&((*tree)->left), value));
		}
	}

	return (NULL);
}

/**
 * bst_insert - Insert a value in a binary search tree.
 *
 * @tree: tree root node pointer.
 * @value: value to be inserted.
 * Return: Pointer to the inserted node.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	return (insert_node(tree, value));
}
