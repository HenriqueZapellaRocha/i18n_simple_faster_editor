#ifndef PARSINGTREE_H
#define PARSINGTREE_H
 
typedef struct PARSING_TREE {
    char *name;
    char node_type_object;
    struct PARSING_TREE **childrens;
    int childrens_len;
} PARSING_TREE;

PARSING_TREE *create_tree(char *name, char node_type);
PARSING_TREE *add_children(char *name, char node_type, PARSING_TREE *tree);
void print_tree(PARSING_TREE *tree);
PARSING_TREE *last_in_base_path(PARSING_TREE *root);

#endif 
