#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number (for error reporting), unused in this function.
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void) line_number;  /* Unused variable */

    if (!stack)
    {
        fprintf(stderr, "L%d: stack not found\n", line_number);
        exit(EXIT_FAILURE);
    }

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
