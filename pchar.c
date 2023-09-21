#include "monty.h"
/**
 * pchar_stack - pchars of ascii value given as args
 * @line_number: integer
 * @stack: head node of stack
 * Return: a new node
 */
void pchar_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int ascii_value;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}

	ascii_value = temp->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}

	putchar(ascii_value);
	putchar('\n');
		
}
