#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of heap
 *
 * Return: the value stored in the root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
    heap_t *last_node, *temp;
    int value;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    last_node = get_last_node(*root);
    if (!last_node)
        return (0);

    if (last_node->parent)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }

    if (last_node != *root)
    {
        (*root)->n = last_node->n;
        temp = *root;
        *root = last_node;
        last_node = temp;
    }

    rebuild_heap(*root);

    free(last_node);
    return (value);
}
