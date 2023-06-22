#include "monty.h"

/**
* push - Adds a node to the stack.
* @head: Double pointer to the head node of the stack.
* @counter: Line number of the command in the Monty file.
* Return: void
*/
void push(stack_t **head, unsigned int counter)
{
int n = 0;
char *arg = monty_state.arg;

/* Check if arg is present and is a valid integer */
if (arg == NULL || (!is_integer(arg)))
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
handle_error(head, EXIT_FAILURE);
}

/* Convert argument to integer */
n = atoi(arg);

/* Add the node to stack or queue based on LIFO/FIFO flag */
if (monty_state.lifi == 0)
{
add_node(head, n);
}
else
{
append_node(head, n);
}
}

/**
* is_integer - Checks if the given string is a valid integer.
* @s: The string to check.
* Return: 1 if the string is a valid integer, 0 otherwise.
*/
int is_integer(char *s)
{
int i = 0;

/* If the string starts with a minus sign, skip it */
if (s[i] == '-')
{
i++;
}

/* Ensure all remaining characters are digits */
for (; s[i] != '\0'; i++)
{
if (!isdigit(s[i]))
{
return (0);
}
}

return (1);
}

/**
* handle_error - Closes the file, frees the content and the stack,
*                then exits the program with a failure status.
* @head: Double pointer to the head node of the stack.
* @exit_status: The status to exit the program with.
* Return: void
*/
void handle_error(stack_t **head, int exit_status)
{
fclose(monty_state.file);
free(monty_state.content);
free_stack(*head);
exit(exit_status);
}
