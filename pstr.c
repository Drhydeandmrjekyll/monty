#include "monty.h"

/**
* pstr - Prints the string starting at the
*        top of the stack, followed by a newline.
*
* @head: Double pointer to the head node of the stack.
* @counter: The line number of the command in the
*           Monty file. Not used in this function.
*
* Return: void
*/
void pstr(stack_t **head, unsigned int counter)
{
stack_t *currentNode;
char ch;

(void)counter;

/* Start from the head of the stack */
currentNode = *head;

while (currentNode)
{
/* Break the loop if the character code is not printable */
if (currentNode->n <= 0 || currentNode->n > 127)
{
break;
}

ch = currentNode->n;
printf("%c", ch);

#ifdef DEBUG
printf("[DEBUG] Printed character: %c (ASCII: %d)\n", ch, ch);
asm("int $3");
#endif

/* Move to the next node */
currentNode = currentNode->next;
}

/* Print a newline at the end */
printf("\n");
}
