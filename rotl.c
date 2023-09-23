#include "monty.h"
/**
 * rotl_stack - rotls top two elements of a  stack
 * @line_number: integer
 * @stack: head node of stack
 * Return: a new node
 */
void rotl_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *second, *temp = *stack;

	(void)line_number;
	if (temp == NULL || temp->next == NULL)
		return;
	while (temp->next)
		temp = temp->next;
	second = (*stack)->next;
	temp->next = (*stack);
	(*stack)->prev = temp;
	(*stack)->next = NULL;
	*stack = second;
	second->prev = NULL;
}
