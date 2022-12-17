import "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    size_t depth_first, depth_second;

    if (!first || !second)
        return (NULL);

    for (depth_first = 0; first; depth_first++)
        first = first->parent;
    for (depth_second = 0; second; depth_second++)
        second = second->parent;

    while (depth_first > depth_second)
    {
        first = first->parent;
        depth_first--;
    }
    while (depth_second > depth_first)
    {
        second = second->parent;
        depth_second--;
    }

    while (first && second && first != second)
    {
        first = first->parent;
        second = second->parent;
    }

    return ((binary_tree_t *)first);
}
