#include "monty.h"

/**
 * add_dnodeint - add node
 *
 * @head: head list
 * @n: element
 *
 * Return: new element
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		_putserr("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * add_dnodeint_end - add node end
 *
 * @head: head
 * @n: element
 *
 * Return: new element
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *last;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		_putserr("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;

	last->next = new;
	new->prev = last;

	return (new);
}

/**
 * free_dlistint - frees dlistint
 *
 * @head: head
 *
 * Return: nothing
 */

void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
