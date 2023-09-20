#include "monty.h"
/**
 * swap_stack - swaps top two elements of a  stack
 * @line_number: integer
 * @stack: head node of stack
 * Return: a new node
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int first, second;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = temp->next->n;
	(*stack)->n = second;
	temp->next->n = first;

}
