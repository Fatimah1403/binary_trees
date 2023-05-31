#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_insert_left - inside a node as the left-child of another node.
 * @parent: pointer to the node to insert the left-child in.
 * @value: value to put in the new node
 *
 * Return: the new created node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL || value == '\0')
		return (NULL);

	newNode = malloc(sizeof(binary_tree_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = value;
	newNode->parent = parent;
	newNode->left = parent->left;
	newNode->right = NULL;
	parent->left = newNode;
	if (newNode->left)
	{
		newNode->left->parent = newNode;
	}
	return (newNode);

}
