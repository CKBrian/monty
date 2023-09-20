#include "monty.h"
/**
 * pop_stack - removes a stack element
 * @line_number: integer
 * @stack: head node of stack
 * Return: a new node
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(*stack);
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	temp->prev = (*stack)->prev;
	free(*stack);
	*stack = temp;
}
