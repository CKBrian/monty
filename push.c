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

	if (data_lib->pushErr == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}
	if (data_lib->queue == 1)
	{
		add_queue_end(stack, data_lib->value);
		return;
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		free(data_lib);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack)
		temp->prev = newnode;
	*stack = newnode;
	newnode->n = data_lib->value;
}
