#include "monty.h"

/**
* pall - Prints all the elements of a stack starting from the top.
*
* @head: Double pointer to the head node of the stack.
* @counter: The line number of the command in the Monty file. Not used here,
*           so we mark it as unused to avoid compiler warnings.
*
* Return: void.
*/
void pall(stack_t **head, unsigned int counter __attribute__((unused)))
{
stack_t *h;

h = *head;
if (h == NULL)
return;

while (h)
{
printf("%d\n", h->n);
h = h->next;

/* Add a gdb macro to assist in debugging */
#ifdef DEBUG
asm("int $3");
#endif
}
}
