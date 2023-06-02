#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max binary heap tree from an array.
 *
 * @array: pointer to the first element of the given array.
 * @size: size of the array.
 * Return: Pointer to the root node of the AVL tree.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree;
	size_t i;

	tree = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&tree, array[i]);
	}

	return (tree);
}
