#include "reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_spaces( char *line_file );
void recognize_base_path( FILE *json_file );

void read_and_parse_json(const char *file_name) {
    FILE *json_file = fopen( file_name, "r" );

    //@TODO: turn this on a malloc to read a complete line 
    if ( json_file == NULL ) {
        printf("ERROR: Can`t open this file");
        exit(-1);
    }
    recognize_base_path(json_file);

} 

void remove_spaces( char *line_file ) {
    int i = 0; int j = 0;
    char new_buffer[256];

    while ( line_file[i] != '\0' ) {
        char c = line_file[i];
        if( c != ' ' &&  c != '\t' && c != '\n' ) { // space or tab
            new_buffer[j++] = c;
        }
        i++;
    }
    new_buffer[j] = '\0';
    strcpy(line_file, new_buffer);
    
}

void recognize_base_path( FILE *json_file ) {
    char recognized_base_path_token = 0;
    char buffer[256];

    while ( fread( buffer, sizeof(char), sizeof(buffer), json_file ) > 0 ) {

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
        printf("%s", tokens);
        while ((tokens = strtok(NULL, ".") ) != NULL) {
            printf("\n%s", tokens);
        }
        

    }
}