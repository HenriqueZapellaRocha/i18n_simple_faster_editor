#ifndef PARSINGTREE_H
#define PARSINGTREE_H

#define NODE_TYPE_OBJECT char // -> don`t know it wil bee really necessary, adding if its will be. @todo analyze this
 
typedef struct parsing_tree {
    char *name;
    NODE_TYPE_OBJECT node_type_object;
    parsing_tree *childrens;
} PARSING_TREE;

PARSING_TREE *create_tree( char *name, NODE_TYPE_OBJECT node_type );

#endif 
