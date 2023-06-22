#include "monty.h"
/**
 * pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pop(stack_t **head, cmd_t *cmd, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(cmd->fd);
		free(cmd->line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
