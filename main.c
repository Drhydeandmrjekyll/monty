#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

#define MAX_LEN 1024

/**
 * is_number - Check if a string is a number
 * @s: The string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *s)
{
    int i = 0;

    /* Handle negative numbers */
    if (s[0] == '-')
        i = 1;
    for (; s[i]; i++)
    {
        if (!isdigit((unsigned char)s[i]))
            return 0;
    }
    return 1;
}

/**
 * main - Main entry point for the Monty interpreter.
 * @argc: Number of arguments passed.
 * @argv: Argument vector.
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    char line[MAX_LEN], *opcode = NULL, *arg = NULL;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    FILE *file;

    /* Check usage and open file */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Process each line in the file */
    while (fgets(line, MAX_LEN, file))
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;
        if (strcmp(opcode, "push") == 0)
        {
            arg = strtok(NULL, " \t\n");
            if (arg == NULL || is_number(arg) == 0)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free(stack);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
        /* TODO: Implement a function to find and execute the opcode */
    }

    /* Cleanup */
    free(stack);
    fclose(file);
    return EXIT_SUCCESS;
}
