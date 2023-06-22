#include "monty.h"

/**
* set_queue_format - modifies the stack to behave as a queue (FIFO)
* @top: pointer to the top of the stack/queue
* @line_number: line number in the file
*/
void set_queue_format(stack_t **top, unsigned int line_number)
{
(void) top;
(void) line_number;

monty_state.lifi = 1;
}

/**
* clear_stack - clear the memory of a stack_t stack
* @top: pointer to the stack to be cleared
*/
void clear_stack(stack_t *top)
{
stack_t *temp_node;

while (top)
{
temp_node = top;
top = top->next;
free(temp_node);
}
}
