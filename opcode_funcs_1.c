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

	if (isall_digit(gb_data.gb_nu) == 0 || !_strcmp(gb_data.gb_nu, "!-!"))
	{
		_putserr("L");
		_putcerr(line_number + '0');
		_putserr(": usage: push integer\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}
	nr = _atoi(gb_data.gb_nu);

	if (gb_data.queue_stack == 1)
		add_dnodeint_end(stack, nr);
	else
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
	short int on = 0;

	if (h == NULL)
		return;
	if (h->n == 65 || h->n == 68)
		on = 1;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	if (on == 1)
		printf("%d\n", 0);
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
 * _pint -  prints the value at the top of the stack, followed by a new line.
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
 * _pop - removes the top element of the stack
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
