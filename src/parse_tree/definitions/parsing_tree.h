#ifndef PARSINGTREE_H
#define PARSINGTREE_H

#define NODE_TYPE_OBJECT char // -> don`t know it wil bee really necessary, adding if its will be. @todo analyze this
 
typedef struct PARSING_TREE {
    char *name;
    NODE_TYPE_OBJECT node_type_object;
    struct PARSING_TREE **childrens;
    int childrens_len;
} PARSING_TREE;

PARSING_TREE *create_tree( char *name, NODE_TYPE_OBJECT node_type );
PARSING_TREE *add_children( char *name, NODE_TYPE_OBJECT node_type, PARSING_TREE *tree );

#endif 
