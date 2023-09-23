#include "monty.h"
/**
 * rotr_stack - inverts the stack making top element to be the last 
 * @line_number: integer
 * @stack: stack node of stack
 * Return: a new node
 */
void rotr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *ptemp = NULL, *ntemp = *stack;

	(void)line_number;
	if (*stack == NULL)
		return;
	while (ntemp->next != NULL)
	{
		ntemp = ntemp->next;
		(*stack)->next = ptemp;
		(*stack)->prev = ntemp;
		ptemp = *stack;
		*stack = ntemp;
	}
	(*stack)->next = ptemp;
	(*stack)->prev = NULL;

}
