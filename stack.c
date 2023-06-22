#include "monty.h"

/**
* stack_mode - sets the data structure to stack mode (LIFO)
* @stack_top: pointer to the top of the stack
* @line_num: line number from the bytecode file
*
* Return: None
*/
void stack_mode(stack_t **stack_top, unsigned int line_num)
{
(void)stack_top;
(void)line_num;

monty_state.lifi = 0;
}
