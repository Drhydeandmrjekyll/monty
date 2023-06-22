#include "monty.h"

/**
* add_node - add node to the head stack
* @head: head of the stack
* @n: new value
*
* Return: no return
*/
void add_node(stack_t **head, const int n)
{
stack_t *new_node;
stack_t *aux;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: Malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;

if (*head != NULL)
{
aux = *head;
aux->prev = new_node;
}

*head = new_node;
}
