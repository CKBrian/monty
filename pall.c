#include "monty.h"
/**
 * print_stack - prints the elements of a stack
 * @stack: head node of the stack
 * @line_number: line number
 * Return: nothing
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (data_lib->history == 0 && temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	data_lib->history = 0;
}
