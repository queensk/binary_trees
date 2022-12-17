#include "binary_trees.h"

/**
 * binary_tree_is_avl - finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node;

    if (!tree)
        return (NULL);

    if (!*tree)
    {
        *tree = binary_tree_node(*tree, value);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        new_node = avl_insert(&(*tree)->left, value);
        (*tree)->left = new_node;
    }
    else if (value > (*tree)->n)
    {
        new_node = avl_insert(&(*tree)->right, value);
        (*tree)->right = new_node;
    }
    else
        return (NULL);

    (*tree)->height = 1 + MAX((*tree)->left ? (*tree)->left->height : 0, (*tree)->right ? (*tree)->right->height : 0);
    *tree = binary_tree_balance(*tree);

    return (new_node);
}
