#include "monty.h"
/**
 * rotr_stack - inverts the stack making top element to be the last
 * @line_number: integer
 * @stack: stack node of stack
 * Return: a new node
 */
void rotr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t  *temp = *stack, *second = NULL;
	(void)line_number;
	if (temp == NULL || temp->next == NULL)
		return;

	while (temp->next->next)
		temp = temp->next;
	second = temp;
	temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;

	*stack = temp;
	if (second)
		second->next = NULL;
}
