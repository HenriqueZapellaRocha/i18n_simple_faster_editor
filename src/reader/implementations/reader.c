#include "../definitions/reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../parse_tree/definitions/parsing_tree.h"

typedef unsigned char bool;
#define true 1
#define false 0

void remove_spaces(char *line_file);
PARSING_TREE *recognize_base_path(FILE *json_file);
int read_value(FILE *json_file, PARSING_TREE *root, char *buffer[], char *recognized_value, char *end);
void print_node(PARSING_TREE *node);
void state_machine_value_reader(FILE *json_file, PARSING_TREE *root);
int value_or_object(char *buffer, PARSING_TREE *actual_node, bool *unfinished_read_value_name, bool *unfinished_read, 
                                                                            char *unfinished_read_value_name_buffer[]);


void read_and_parse_json(const char *file_name) {
    FILE *json_file = fopen(file_name, "r");

    if (json_file == NULL) {
        printf("ERROR: Can`t open this file");
        exit(1);
    }

    PARSING_TREE *root = recognize_base_path(json_file);  

    //@TODO retire debug prints
    print_node(root);
    print_tree(root);
    state_machine_value_reader(json_file, root);


} 

int read_value(FILE *json_file, PARSING_TREE *root, char *buffer[], char *recognized_value, char *end){

    if(fscanf(json_file,"%255[^;]%c", buffer, end) > - 1 ) {
        remove_spaces(buffer);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(!(*recognized_value)) {
            char *key   = strtok(buffer, "=");
            char *value = strtok(NULL, "=");

            if(strcmp(key, "value")) { // <- this is strange but in C strcmp returns 0 when the both are equal and i > 0 when not equal
                printf("Value not specified or a error in writing!\nbase_path is mandatory, if you don`t want it use instead: base_path=");
                exit(1);
            }
            *recognized_value = 1;
            char base_path[256];
            strncpy(buffer, value, sizeof(base_path)-1);
            base_path[sizeof(base_path)-1] = '\0';

            return 1;
        }
    } else {
        return 0;
    }
}

void state_machine_value_reader(FILE *json_file, PARSING_TREE *root) {
    PARSING_TREE *actual_object_node = last_in_base_path(root);
    char buffer[256];
    char unfinished_read_value_name_buffer[256];
    char recognized_value = '0';
    bool unfinished_read = false; // <- flag for the state when the value to be read at the moment is not complete in the actual
    bool unfinished_read_value_name = false;
    char end = '0';

    int i = 0;

    while (read_value) {
    
        while(i < sizeof(buffer) / sizeof(buffer[0])) {
            switch (buffer[i])  {
                case '\"':
                    i = start_value_object(&buffer[i+1], actual_object_node);
                    if(i == -1)
                        unfinished_read = true;
                    break;
                
                default:
                    break;
            } 
        }
    }
}

int value_or_object(char *buffer, PARSING_TREE *actual_node, bool *unfinished_read_value_name, bool *unfinished_read, 
                                                                                        char *unfinished_read_value_name_buffer[]) {

    size_t len = strlen(buffer);
    char *pos = strchr(buffer, "\"");

    if(pos != NULL) {
        int pos_index = pos - buffer;
        if(pos_index >= len) {

        }
    } 
    else 
        return -1;

    return;
}

void remove_spaces(char *line_file) {
    int i = 0; int j = 0;
    char new_buffer[256];

    while (line_file[i] != '\0') {
        char c = line_file[i];
        if(c != ' ' &&  c != '\t' && c != '\n') { // space or tab or enter
            new_buffer[j++] = c;
         }
        i++;
    }
    new_buffer[j] = '\0';
    strcpy(line_file, new_buffer);
    
}

PARSING_TREE *recognize_base_path(FILE *json_file) {
    char recognized_base_path_token = 0;
    char buffer[256];
    PARSING_TREE *last_tree = NULL;
    PARSING_TREE *root = NULL;
    char end = ' ';

    while (fscanf(json_file, "%255[^;]%c", buffer, &end)) {
        remove_spaces(buffer);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(!(recognized_base_path_token)) {
            char *key   = strtok(buffer, "=");
            char *value = strtok(NULL, "=");

            if(strcmp(key, "base_path")) { // <- this is strange but in C strcmp returns 0 when the both are equal and i > 0 when not equal
                printf("Base path not specified or a error in writing!\nbase_path is mandatory, if you don`t want it use instead: base_path=");
                exit(1);
            }
            recognized_base_path_token = 1;
            char base_path[256];
            strncpy(buffer, value, sizeof(base_path)-1);
            base_path[sizeof(base_path)-1] = '\0';
        }

        char *tokens = strtok(buffer, ".");
        if(last_tree == NULL) {   
            last_tree = create_tree(tokens, '1');
            root = last_tree;
            // print_node(last_tree);
        }
        else {
            last_tree = add_children(tokens, '1', last_tree);
            print_node(last_tree);
        }

        while ((tokens = strtok(NULL, ".")) != NULL) {
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

