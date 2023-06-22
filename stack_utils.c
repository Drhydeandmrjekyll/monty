#include "monty.h"

/**
* free_stack - Frees a stack_t stack.
* @head: A pointer to the top (head) of a stack_t.
*
* Description: This function traverses a stack represented by the pointer
* `head`, freeing each node until it has traversed the entire stack.
* It's a part of garbage collection process, used for freeing up memory
* that was previously allocated for the stack, but is no longer required.
*
* Return: Void.
*/
void free_stack(stack_t *head)
{
stack_t *temp;

while (head != NULL)
{
temp = head->next;
free(head);
head = temp;
}
}
