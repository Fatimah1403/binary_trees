#include "binary_trees.h"

/**
 * height - Measures and returns the height of a tree.
 *
 * @tree: Pointer to the root node of the tree.
 * Return: The value of the height of the tree.
 */
int height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (-1);

	left = height(tree->left);
	right = height(tree->right);

	if (left > height)
		return (left + 1);

	return (right + 1);
}


/**
 * tree_is_perfect - Checks if binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if true, 0 otherwise.
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	left = height(tree->left);
	right = height(tree->right);

	if (tree && left == right)
	{
		if (left == -1)
			return (1);

		if ((tree->left && !((tree->left)->left)
				&& !((tree->left)->right))
				&& (tree->right && !((tree->right)->left)
				&& !((tree->right)->right)))
			return (1);

		if (tree && tree->left && tree->right)
			return (tree_is_perfect(tree->left) &&
				tree_is_perfect(tree->right));
	}

	return (0);
}


/**
 * swap - swaps nodes when child is greater than parent
 *
 * @arg_node: parent node
 * @arg_child: child node
 * Return: no return
 */
void swap(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *arg_node, child = *arg_child;

	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;

		node_left = child->left, node_right = child->right;

		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *arg_node = child;
	}
}


/**
 * heap_insert - Inserts a value in Max Binary tree Heap.
 *
 * @value: value of node to be inserted.
 * @root: tree root node pointer.
 * Return: Pointer to the created node, or NULL if not created.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (tree_is_perfect(*root) || !tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new_node = heap_insert(&((*root)->left), value);
			swap(root, &((*root)->left));
			return (new_node);
		}
		else
		{
			new_node = (*root)->left = binary_tree_node(*root, value);
			swap(root, &((*root)->left));
			return (new_node);
		}
	}

	if ((*root)->right)
	{
		new_node = heap_insert(&((*root)->right), value);
		swap(root, (&(*root)->right));
		return (new_node);
	}
	else
	{
		new_node = (*root)->right = binary_tree_node(*root, value);
		swap(root, &((*root)->right));
		return (new_node);
	}
	return (NULL);
}
