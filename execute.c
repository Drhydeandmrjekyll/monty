#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line counter
* @file: pointer to monty file
* @content: line content
* Return: 0 if successful, 1 otherwise
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opst[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"nop", nop},
{"pstr", pstr},
{"queue", set_queue_format},
{"stack_mode", stack_mode},
{NULL, NULL}
};
unsigned int i;
char *op;

op = strtok(content, " \n\t");
if (op && op[0] == '#')
{
return (0);
}

monty_state.arg = strtok(NULL, " \n\t");
for (i = 0; opst[i].opcode && op; i++)
{
if (strcmp(op, opst[i].opcode) == 0)
{
opst[i].f(stack, counter);
return (0);
}
}

if (op && opst[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}

return (1);
}
