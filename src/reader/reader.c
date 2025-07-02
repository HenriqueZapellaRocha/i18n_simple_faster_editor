#include "reader.h"
#include <stdio.h>
#include <stdlib.h>

void read_and_parse_json(const char *file_name) {

    FILE *file = fopen( file_name, "r" );

    if ( file == NULL )
        exit(-1);

    
} 