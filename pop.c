#include "monty.h"

/**
* pop - Removes the top element of the stack.
*
* @head: Double pointer to the head node of the stack.
* @counter: The line number of the command in the Monty file.
*
* If the stack is empty, handle the error by printing
* a specific message to standard error, free the associated
* resources, and exit with status EXIT_FAILURE.
*
* Return: void.
*/
void pop(stack_t **head, unsigned int counter)
{
stack_t *tempNode;

/* If the stack is not empty, remove the top element */
if (*head != NULL)
{
tempNode = *head;
*head = (*head)->next;

#ifdef DEBUG
printf("[DEBUG] Removed the top element of the stack: %d\n", tempNode->n);
asm("int $3");
#endif

free(tempNode);
}
else
{
/* Print error message, free resources and exit if stack is empty */
fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
fclose(monty_state.file);
free(monty_state.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
}
