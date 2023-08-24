#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with
 *		the top element of the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int i, vl;

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
		_putserr(": can't mul, stack too short\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	vl = (*stack)->n;
	*stack = (*stack)->next;
	free(aux);
	(*stack)->n *= vl;
}
