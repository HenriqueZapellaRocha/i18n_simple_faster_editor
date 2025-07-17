#include "../definitions/simple_stack.h"
#include "../../parse_tree/definitions/parsing_tree.h"
#include <stdlib.h>
#include <stdio.h>


void validate_sended_stack_and_initialize(PARSING_TREE *value_pointer, SIMPLE_STACK *stack) ;

SIMPLE_STACK *add_value_in_stack(PARSING_TREE *value_pointer, SIMPLE_STACK *stack) {
    validate_sended_stack_and_initialize(value_pointer, stack);
    if (stack->lenght <= stack->last_index_value + 1) {
        stack->values = realloc(stack->values, sizeof(PARSING_TREE*) * (stack->lenght * 2));
        stack->lenght = stack->lenght * 2;
    }

    stack->values[stack->last_index_value+1] = value_pointer;
    stack->last_index_value++;
    return stack;
}


void pop_value_from_stack(SIMPLE_STACK *stack) {
    if(stack->last_index_value < 0)
        return;

    if (stack != NULL && stack->values != NULL && stack->last_index_value >= 0) {
        free(stack->values[stack->last_index_value]);
        stack->last_index_value--;
    }
    else {
        fprintf(stderr, "Stack sent is null in pop function\n");

    }
}

void validate_sended_stack_and_initialize(PARSING_TREE *value_pointer, SIMPLE_STACK *stack) {
        if(stack == NULL) 
            printf(stderr, "error in stack, given a NULL stack");
            exit(1);
        if (&value_pointer == NULL || value_pointer == NULL)
            printf(stderr, "values recived to add in stack is null");
            exit(1);
        if (stack->values == NULL) {
            stack->values = malloc(sizeof(PARSING_TREE*) * 5);
            stack->lenght = 5; stack->last_index_value = -1;
        }
}