#include "monty.h"
/**
 * free_stack - frees a stack
 * @stack: pointer to stack node
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = stack;

	while (temp)
	{
		temp = temp->next;
		free(stack);
		stack = temp;
	}
}
