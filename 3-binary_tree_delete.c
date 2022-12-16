#include "binary_trees.h"

/**
 * Recursively deletes a binary tree using post-order traversal.
 *
 * @tree: Pointer to the root node of the tree to delete
 *
 * The function first checks if the tree is NULL, in which case it returns
 * immediately. If the tree is not NULL, the function recursively deletes the
 * left and right subtrees of the tree using the binary_tree_delete() function
 * itself. Finally, it frees the memory occupied by the tree node by calling
 * free().
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
    free(tree);
}
