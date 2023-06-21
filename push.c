#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: value of the new element
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new;

    if (!stack)
    {
        fprintf(stderr, "L%d: stack not found\n", line_number);
        exit(EXIT_FAILURE);
    }

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = line_number;
    new->prev = NULL;
    new->next = NULL;

    if (*stack != NULL)
    {
        new->next = *stack;
        (*stack)->prev = new;
    }
    *stack = new;
}
