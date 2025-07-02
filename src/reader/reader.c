#include "reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_spaces( char *line_file );
void recognize_base_path( const char *file_name );

void read_and_parse_json(const char *file_name) {

    FILE *json_file = fopen( file_name, "r" );

    //@TODO: turn this on a malloc to read a complete line 
    char buffer[256]; 

    if ( json_file == NULL )
        exit(-1);
    
    fgets( buffer, sizeof(buffer), json_file );


    remove_spaces(buffer);

    char *base_path = strtok(buffer, "=");
    if( !strcmp(base_path, "base_path") )
        printf("deu bom");
    printf("value\n%s", strtok(NULL, "="));

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