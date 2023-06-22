#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* doubly linked list representation of a stack (or queue) */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* Carries values through the program */
typedef struct monty_state_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  monty_state_t;

extern monty_state_t monty_state;

/* Opcode and its function */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void push(stack_t **head, unsigned int number);
void pall(stack_t **head, unsigned int number);
void pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *stack_top);
void pop(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void add_node(stack_t **head, int n);
void set_queue_format(stack_t **top, unsigned int line_number);
void clear_stack(stack_t *top);
void stack_mode(stack_t **stack_top, unsigned int line_num);
void handle_error(stack_t **head, int exit_status);
int is_integer(char *s);
void append_node(stack_t **top, int value);



#endif
