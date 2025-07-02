#include "parsing_tree.h"
#include <stdlib.h>

PARSING_TREE *create_tree( char *name, NODE_TYPE_OBJECT node_type ) {
    PARSING_TREE *parsing_tree;
    parsing_tree->name = name;
    parsing_tree->node_type_object = node_type;
    parsing_tree->childrens = NULL;

    return parsing_tree;
}