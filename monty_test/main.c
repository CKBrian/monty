#include "monty.h"

/**
* main - Entry point of the Monty bytecode interpreter.
* @argc: Number of command-line arguments.
* @argv: Array of command-line argument strings.
* Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	size_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

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

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \n");

		if (!opcode)
			continue;

		if (strcmp(opcode, "push") == 0)
			push(&stack, line_number);
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		else if (strcmp(opcode, "pint") == 0)
			pint(&stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			pop(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
