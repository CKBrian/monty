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
	newnode->n = data_lib->value;
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack)
		temp->prev = newnode;
	*stack = newnode;
}
