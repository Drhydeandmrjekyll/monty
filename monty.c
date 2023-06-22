#include "monty.h"

/**
* struct monty_state_s - carries values through the program
* @arg: value
* @file: pointer to monty file
* @content: line content
* @lifi: flag change stack <-> queue
*/
monty_state_t monty_state = {NULL, NULL, NULL, 0};

/**
* handle_memory_error - Checks if a memory allocation has succeeded
* @ptr: The pointer to check
*
* If the memory allocation has failed, the function prints an error message
* and terminates the program.
*/
void handle_memory_error(void *ptr)
{
if (!ptr)
{
fprintf(stderr, "Error: Memory allocation failed\n");
exit(EXIT_FAILURE);
}
}

/**
* get_line - Reads a line from the given file
* @line: A pointer to the buffer that will store the line
* @file: The file from which to read the line
*
* Return: The number of characters in the line, or -1 if the end of the file
* is reached
*/
ssize_t get_line(char **line, FILE *file)
{
int ch;
int size = 0;
int capacity = 1024;
char *buffer = malloc(capacity);

handle_memory_error(buffer);

for (ch = fgetc(file); ch != '\n' && ch != EOF; ch = fgetc(file))
{
if (size + 1 >= capacity)
{
capacity *= 2;
buffer = realloc(buffer, capacity);
handle_memory_error(buffer);
}
buffer[size++] = ch;
}
buffer[size] = '\0';

*line = buffer;
return ((ch == EOF && size == 0) ? -1 : size);
}

/**
* main - entry point to the program
* @argc: argument count
* @argv: argument vector
*
* Return: always 0 (success)
*/
int main(int argc, char **argv)
{
char *content;
FILE *file;
ssize_t read_line;
stack_t *stack = NULL;
unsigned int counter = 0;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
monty_state.file = file;

for (read_line = get_line(&content, file);
read_line > 0;
read_line = get_line(&content, file))
{
monty_state.content = content;
counter++;
if (read_line >= 0)
{
execute(content, &stack, counter, file);
}
free(content);
}

free_stack(stack);
fclose(file);

return (0);
}
