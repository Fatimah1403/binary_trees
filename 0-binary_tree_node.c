#include "binary_trees.h"

/**
 * binary_tree_node - function to create a binary tree node
 * @parent: pointer to the parent node
 * @value: value to put in the new node
 *
 * Return: the new created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	/* allocate new memory*/

	newNode = malloc(sizeof(binary_tree_t));
	if (newNode == NULL)
		return (NULL);

	newNode->parent = parent;
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
