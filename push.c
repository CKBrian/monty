#include "monty.h"
/**
 * push_stack - creates a stack
 * @line_number: integer
 * @stack: head node of stack
 * Return: a new node
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode, *temp = *stack;

	(void)line_number;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = globvalue;
	if (*stack == NULL)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		*stack = newnode;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		newnode->next = temp->next;
		temp->next = newnode;
		newnode->prev = temp;
	}
}
