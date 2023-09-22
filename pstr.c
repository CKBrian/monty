#include "monty.h"
/**
 * pstr_stack - pstrs top two elements of a  stack
 * @line_number: integer
 * @stack: head node of stack
 * Return: a new node
 */
void pstr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void)line_number;

	while (curr != NULL && curr->n >= 1 && curr->n <= 127)
	{
		putchar(curr->n);
		curr = curr->next;
	}

	putchar('\n');
}
