#include "../definitions/reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../parse_tree/definitions/parsing_tree.h"

void remove_spaces( char *line_file );
PARSING_TREE *recognize_base_path( FILE *json_file );
void read_value( FILE *json_file, PARSING_TREE *root );
void print_node( PARSING_TREE *node ) ;

void read_and_parse_json(const char *file_name) {
    FILE *json_file = fopen( file_name, "r" );

    if ( json_file == NULL ) {
        printf("ERROR: Can`t open this file");
        exit(-1);
    }

    PARSING_TREE *root = recognize_base_path(json_file);

    printf("porra de rrot:\n");
    print_node(root);
    print_tree(root);
    read_value( json_file, root );

} 

void read_value( FILE *json_file, PARSING_TREE *root ){


}

void remove_spaces( char *line_file ) {
    int i = 0; int j = 0;
    char new_buffer[256];

    while ( line_file[i] != '\0' ) {
        char c = line_file[i];
        if( c != ' ' &&  c != '\t' && c != '\n' ) { // space or tab or enter
            new_buffer[j++] = c;
        }
        i++;
    }
    new_buffer[j] = '\0';
    strcpy(line_file, new_buffer);
    
}

PARSING_TREE *recognize_base_path( FILE *json_file ) {
    char recognized_base_path_token = 0;
    char buffer[256];
    PARSING_TREE *last_tree = NULL;
    PARSING_TREE *root = NULL;
    char end = ' ';

    while (fscanf(json_file, "%255[^;]%c", buffer, &end)) {
        printf("last valueeeeeee%c\n",end);
        
        buffer[strcspn(buffer, "\n")] = '\0';

        if( !( recognized_base_path_token ) ) {
            char *key   = strtok(buffer, "=");
            char *value = strtok(NULL, "=");

            if( strcmp(key, "base_path") ) { // <- this is strange but in C strcmp returns 0 when the both are equal and i > 0 when not equal
                printf("Base path not specified or a error in writing!\nbase_path is mandatory, if you don`t want it use instead: base_path=");
                exit(1);
            }
            recognized_base_path_token = 1;
            char base_path[256];
            strncpy(buffer, value, sizeof(base_path)-1);
            base_path[sizeof(base_path)-1] = '\0';
        }

        char *tokens = strtok(buffer, ".");
        if( last_tree == NULL ) {   
            last_tree = create_tree(tokens, '1');
            root = last_tree;
            // print_node(last_tree);
        }
        else {
            last_tree = add_children(tokens, '1', last_tree);
            print_node(last_tree);
        }

        while ((tokens = strtok(NULL, ".") ) != NULL) {
            last_tree = add_children(tokens, '1', last_tree);
            print_node(last_tree);
        }
        if(end == ';') break;
    }

    return root;
}

void print_node(PARSING_TREE *node) {
    if (node == NULL) {
        fprintf(stderr, "print_node: node é NULL!\n");
        return;
    }

    printf("name: %s\n", node->name);
    printf("childrens_len: %d\n", node->childrens_len);
    printf("node_type_object: %c\n", node->node_type_object);

}

