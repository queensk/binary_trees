#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL tree
 * @tree: double pointer to the root node of the AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 *
 * If the address stored in tree is NULL, the created node becomes the root node.
 * The resulting tree after insertion is a balanced AVL tree.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node;
    int balance;

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

    (*tree)->height = 1 + MAX((*tree)->left ? (*tree)->left->height : 0,
    (*tree)->right ? (*tree)->right->height : 0);
    balance = binary_tree_balance_factor(*tree);

    if (balance > 1 && value < (*tree)->left->n)
        return (binary_tree_rotate_right(*tree));

    if (balance < -1 && value > (*tree)->right->n)
        return (binary_tree_rotate_left(*tree));

    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return (binary_tree_rotate_right(*tree));
    }

    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return (binary_tree_rotate_left(*tree));
    }

    return (new_node);
}
