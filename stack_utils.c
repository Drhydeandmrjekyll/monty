#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @stack_top: pointer to the top of the stack
*
* Return: None
*/
void free_stack(stack_t *stack_top)
{
stack_t *next_node;

while (stack_top)
{
next_node = stack_top->next;
free(stack_top);
stack_top = next_node;
}
}
