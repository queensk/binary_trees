#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node = NULL;

    if (!tree)
        return (NULL);

    if (!*tree)
    {
        *tree = binary_tree_node(*tree, value);
        return (*tree);
    }

    if (value < (*tree)->n)
        new_node = avl_insert(&(*tree)->left, value);
    else if (value > (*tree)->n)
        new_node = avl_insert(&(*tree)->right, value);
    else
        return (NULL);

    *tree = binary_tree_balance(*tree);

    return (new_node);
}
