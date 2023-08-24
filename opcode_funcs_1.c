#include "monty.h"

/**
 * _push - the opcode push pushes an element to the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int nr;

	if (!isall_digit(gb_data.gb_nu))
	{
		_putserr("L");
		_putcerr(line_number + '0');
		_putserr(": usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	nr = _atoi(gb_data.gb_nu);
	add_dnodeint(stack, nr);
}

/**
 * print_dlistint - print all elements
 *
 * @h: list
 *
 * Return: nothing
 */

void  print_dlistint(const stack_t *h)
{
	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _pall - the opcode pall prints all the values on the stack,
 *		starting from the top of the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}

/**
 * _pint - the opcode pall prints all the values on the stack,
 *              starting from the top of the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		_putserr("L");
		_putcerr(line_number + '0');
		_putserr(": can't pint, stack empty\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - the opcode pall prints all the values on the stack,
 *              starting from the top of the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (*stack == NULL || stack == NULL)
	{
		_putserr("L");
		_putcerr(line_number + '0');
		_putserr(": can't pop an empty stack\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
}
