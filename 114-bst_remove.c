#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where the node will be removed
 * @value: the value to remove from the tree
 *
 * Return: a pointer to the new root node of the tree after removing the desired value, or NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *node, *successor;

    if (!root)
        return NULL;

    /* Find the node to be removed */
    node = root;
    while (node && node->n != value)
    {
        if (value < node->n)
            node = node->left;
        else
            node = node->right;
    }

    if (!node)
        return NULL;

    /* Case 1: Node has no children */
    if (!node->left && !node->right)
    {
        if (node->parent)
        {
            if (node->parent->left == node)
                node->parent->left = NULL;
            else
                node->parent->right = NULL;
        }
        else
            root = NULL;
        free(node);
        return root;
    }

    /* Case 2: Node has one child */
    if (!node->left || !node->right)
    {
        bst_t *child = node->left ? node->left : node->right;
        if (node->parent)
        {
            if (node->parent->left == node)
                node->parent->left = child;
            else
                node->parent->right = child;
        }
        else
            root = child;
        child->parent = node->parent;
        free(node);
        return root;
    }

    /* Case 3: Node has two children */
    successor = node->right;
    while (successor->left)
        successor = successor->left;

    /* Swap values between node and successor */
    node->n = successor->n;

    /* Recursively remove successor */
    bst_remove(successor, successor->n);

    return root;
}
