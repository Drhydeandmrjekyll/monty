#include "monty.h"

/**
* push - pushes an element to the stack
* @stack: double pointer to the top of the stack
* @n: value of the new element
*
* Return: void
*/
void push(stack_t **stack, int n)
{
stack_t *new_node;  /* New node to be added to the stack */

/* Allocate memory for the new node */
new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

/* Initialize the new node */
new_node->n = n;
new_node->prev = NULL;
new_node->next = (*stack) ? *stack : NULL;

/* Update the previous pointer of the old top element */
if (*stack)
{
(*stack)->prev = new_node;
}

/* Point the top of the stack to the new node */
*stack = new_node;
}
