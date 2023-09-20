#include "monty.h"
/**
 * pint_stack - prints the top element of a stack
 * @stack: head node of the stack
 * @line_number: line number
 * Return: nothing
 */
void pint_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		if (*(data_lib->stack))
			free_stack(*(data_lib->stack));
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);

}
