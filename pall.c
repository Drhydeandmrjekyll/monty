#include "monty.h"

/**
* pall - prints all the values on the stack, starting from the top.
* @stack: double pointer to the top of the stack.
* @line_number: line number (for error reporting), unused in this function.
*
* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current;  /* Pointer to traverse the stack */

/* Silence unused variable warning */
(void) line_number;

/* Initialize the current pointer */
current = *stack;

/* Traverse the stack and print values */
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
