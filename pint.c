#include <stdio.h>
#include "monty.h"

/**
* pint - prints the top
* @head: stack head
* @counter: line number
* Return: no return
*/
void pint(stack_t **head, unsigned int counter)
{
/* Check if the stack is empty */
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
