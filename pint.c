#include "monty.h"

/**
* pint - Prints the value at the top of the stack, followed by a new line.
*
* @head: Double pointer to the head node of the stack.
* @counter: The line number of the command in the Monty file.
*
* If the stack is empty, handle error by printing a specific message to
* standard error, free the associated resources, and exit with status EXIT_FAILURE.
*
* Return: void.
*/
void pint(stack_t **head, unsigned int counter)
{
/* Print the value at the top of the stack if it is not empty */
if (*head != NULL)
{
printf("%d\n", (*head)->n);

#ifdef DEBUG
printf("[DEBUG] Printed the top value of the stack: %d\n", (*head)->n);
asm("int $3");
#endif
}
else
{
/* Print error message, free resources and exit if stack is empty */
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(monty_state.file);
free(monty_state.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
}
