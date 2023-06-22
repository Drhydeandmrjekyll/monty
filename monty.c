#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/* Main function */
int main(int argc, char *argv[])
{
stack_t *stack = NULL;
FILE *file;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

file = open_file(argv[1]);

if (file == NULL)
return (EXIT_FAILURE);

if (process_lines(file, &stack) == EXIT_FAILURE)
{
fclose(file);
return (EXIT_FAILURE);
}

free_stack(stack);
fclose(file);

return (EXIT_SUCCESS);
}
