#include "../definitions/parsing_tree.h"
#include <stdlib.h>

PARSING_TREE *create_tree( char *name, NODE_TYPE_OBJECT node_type ) {
    PARSING_TREE *parsing_tree = malloc(sizeof(PARSING_TREE));
    parsing_tree->name = name;
    parsing_tree->node_type_object = node_type;
    parsing_tree->childrens = NULL;
    parsing_tree->childrens_len = -1;

    return parsing_tree;
}

PARSING_TREE *add_children( char *name, NODE_TYPE_OBJECT node_type, PARSING_TREE *tree ) {

    PARSING_TREE *new_children = malloc(sizeof(PARSING_TREE));
    new_children->name = name;
    new_children->childrens_len = 0;
    new_children->node_type_object = node_type;

    tree->childrens_len++;
    tree->childrens = realloc(tree->childrens, sizeof(PARSING_TREE*)*tree->childrens_len);
    tree->childrens[tree->childrens_len] = new_children;

    return new_children;
}