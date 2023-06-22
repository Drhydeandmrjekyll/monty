#include "monty.h"

/**
* swap - swaps the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void swap(stack_t **head, unsigned int counter)
{
stack_t *h = *head;

/* Check if stack contains less than two elements */
if (h == NULL || h->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
fclose(monty_state.file);
free(monty_state.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Swap the top two elements of the stack */
h->n ^= h->next->n;
h->next->n ^= h->n;
h->n ^= h->next->n;
}

