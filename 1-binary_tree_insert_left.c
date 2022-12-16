#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insert a node as the left-child of another node
 *
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    if (parent == NULL)
        return NULL;

    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return NULL;

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	new->left = parent->left;
	parent->left = new;
	if (new->left)
		new->left->parent = new;
	return (new);
}
