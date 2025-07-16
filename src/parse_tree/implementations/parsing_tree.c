#include "../definitions/parsing_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

PARSING_TREE *create_tree(char *name, char node_type) {
    PARSING_TREE *parsing_tree = malloc(sizeof(PARSING_TREE));
    parsing_tree->name = strdup(name);
    parsing_tree->node_type_object = node_type;
    parsing_tree->childrens = NULL;
    parsing_tree->childrens_len = 0;

    return parsing_tree;
}

PARSING_TREE *add_children(char *name, char node_type, PARSING_TREE *tree) {

    PARSING_TREE *new_children = malloc(sizeof(PARSING_TREE));
    new_children->name = strdup(name);
    new_children->childrens_len = 0;
    new_children->node_type_object = node_type;
    new_children->childrens = NULL;

    tree->childrens_len++;
    tree->childrens = realloc(tree->childrens, sizeof(PARSING_TREE*)*tree->childrens_len);
    tree->childrens[tree->childrens_len - 1] = new_children;

    return new_children;
}

void print_tree(PARSING_TREE *tree) {
    if (!tree) return;

    printf("Node(name=\"%s\", type='%c', children=%d)\n",
           tree->name, tree->node_type_object, tree->childrens_len);

    for (int i = 0; i < tree->childrens_len; i++) {
        print_tree(tree->childrens[i]);
    }
}

PARSING_TREE *last_in_base_path(PARSING_TREE *root) {
    PARSING_TREE *actual_node = root;
    while (actual_node != NULL && actual_node->childrens != NULL) {
        actual_node = actual_node->childrens[0];
    }

    if(actual_node == NULL) {
        fprintf(stderr, "ERROR: while searching the last value in base path");
        exit(1);
    }

    return actual_node;
    
}
