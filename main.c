#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * get_line - Reads a line from the given file
 * @line: A pointer to the buffer that will store the line
 * @file: The file from which to read the line
 *
 * Return: The number of characters in the line, or -1 if the end of the file is reached
 */
ssize_t get_line(char **line, FILE *file)
{
	int ch, size = 0, capacity = 1024;
	char *buffer = malloc(capacity);

	if (!buffer)
		return -1;

	while ((ch = fgetc(file)) != '\n' && ch != EOF)
	{
		if (size + 1 >= capacity)
		{
			capacity *= 2;
			buffer = realloc(buffer, capacity);
			if (!buffer)
				return -1;
		}
		buffer[size++] = ch;
	}
	buffer[size] = '\0';

	*line = buffer;
	return (ch == EOF && size == 0) ? -1 : size;
}

int main(int argc, char **argv)
{
	char *content = NULL;
	FILE *file;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		read_line = get_line(&content, file);
		bus.content = content;
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
