#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int i;

	stack_t *aux = NULL;

	i = 0;
	aux = *stack;
	while (aux != NULL)
	{
		aux = aux->next;
		i++;
	}

	if (i < 2)
	{
		_putserr("L");
		_putcerr(line_number + '0');
		_putserr(": can't swap, stack too short\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	*stack = (*stack)->next;
	aux->next = (*stack)->next;
	aux->prev = *stack;
	(*stack)->next = aux;
	(*stack)->prev = NULL;
}
