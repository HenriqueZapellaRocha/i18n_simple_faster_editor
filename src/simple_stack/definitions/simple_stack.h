#ifndef SIMPLE_STACK_H
#define SIMPLE_STACK_H

#include "../parse_tree/definitions/parsing_tree.h"

typedef struct stack {
    PARSING_TREE **values;
    long last_index_value;
    long lenght;
} SIMPLE_STACK;

PARSING_TREE *add_value_in_stack(PARSING_TREE *value_pointer,SIMPLE_STACK *stack);
void pop_value_from_stack(SIMPLE_STACK *stack);

#endif 
