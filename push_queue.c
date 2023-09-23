#include "monty.h"
/**
 * add_queue_end -  adds a new node at the end of a stack_t list
 * @head: pointer to head node
 * @n: integer
 * Return: new element
 */
stack_t *add_queue_end(stack_t **head, int n)
{
	stack_t *newnode = NULL, *temp = *head;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	if (temp == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
	}
	newnode->next = NULL;
	return (newnode);
}
