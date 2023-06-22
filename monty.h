#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct cmd_s - cmd
 * @fd: file descriptor
 * @line: line
 */
typedef struct cmd_s
{
	FILE *fd;
	char *line;
} cmd_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

void push(stack_t **stack, int n);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **head, unsigned int counter);
int process_lines(FILE *file, stack_t **stack);
void find_and_execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
int is_number(char *s);
int process_push(char *arg, stack_t **stack, unsigned int line_number);
int process_opcode(char *opcode, stack_t **stack, unsigned int line_number);
int process_lines(FILE *file, stack_t **stack);
void pop(stack_t **head, cmd_t *cmd, unsigned int counter);
void swap(stack_t **head, cmd_t *cmd, unsigned int counter);

FILE *open_file(char *filename);

void free_stack(stack_t *head);

#endif /* MONTY_H */
