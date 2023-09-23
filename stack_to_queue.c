#include "monty.h"
/**
 * to_stack - converts a queue to a stack
 * @line_number: integer
 * @stack: stack node of stack
 * Return: a new node
 */
void to_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		return;
	if (data_lib->queue == 1)
	{
		/*inverter(stack, line_number);*/
		data_lib->queue = 0;
	}
}
/**
 * to_queue - converts a stack to a queue
 * @line_number: integer
 * @stack: stack node of stack
 * Return: a new node
 */
void to_queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		data_lib->queue = 1;
		return;
	}
	if (data_lib->queue == 0)
	{
		/*inverter(stack, line_number);*/
		data_lib->queue = 1;
	}
}
