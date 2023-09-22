#include "monty.h"
/**
 * mod_stack - mods top two elements of a  stack
 * @line_number: integer
 * @stack: head node of stack
 * Return: a new node
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int first, second;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	if (first == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}
	second = temp->next->n;
	temp = temp->next;
	free(*stack);
	temp->n = second % first;
	*stack = temp;
	temp->prev = NULL;

}
