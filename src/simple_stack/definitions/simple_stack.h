#ifndef SIMPLE_STACK_H
#define SIMPLE_STACK_H

#include "../parse_tree/definitions/parsing_tree.h"

typedef struct stack {
    PARSING_TREE **stack;
    long last_index_value;
} SIMPLE_STACK;

PARSING_TREE *add_value_in_stack(PARSING_TREE *value_pointer, PARSING_TREE *stack[]) {


}

#endif 
