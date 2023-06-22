#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LEN 1024

bus_t bus = {NULL, NULL, NULL, 0};

/* Check if a string is a number */
int is_number(char *s)
{
int i = 0;

if (s[0] == '-')
i = 1;

for (; s[i]; i++)
{
if (!isdigit((unsigned char)s[i]))
return (0);
}

return (1);
}

/* Processes the push operation */
int process_push(char *arg, stack_t **stack, unsigned int line_number)
{
if (arg == NULL || is_number(arg) == 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free_stack(*stack);
return (EXIT_FAILURE);
}

push(stack, atoi(arg));
return (EXIT_SUCCESS);
}

/* Processes the opcode */
int process_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
if (strcmp(opcode, "push") == 0)
{
char *arg = strtok(NULL, " \t\n");
return (process_push(arg, stack, line_number));
}
else
{
find_and_execute_opcode(opcode, stack, line_number);
return (EXIT_SUCCESS);
}
}

/* Processes lines from the file */
int process_lines(FILE *file, stack_t **stack)
{
char line[MAX_LEN];
char *opcode;
unsigned int line_number = 0;

while (fgets(line, MAX_LEN, file) != NULL)
{
line_number++;
opcode = strtok(line, " \t\n");

if (opcode == NULL || opcode[0] == '#')
continue;

if (process_opcode(opcode, stack, line_number) == EXIT_FAILURE)
return (EXIT_FAILURE);
}

return (EXIT_SUCCESS);
}

/* Opens the file */
FILE *open_file(char *filename)
{
FILE *file = fopen(filename, "r");

if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
}

return (file);
}
