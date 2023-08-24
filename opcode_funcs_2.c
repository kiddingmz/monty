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

/**
 * _add - adds the top two elements of the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _add(stack_t **stack, unsigned int line_number)
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
		_putserr(": can't add, stack too short\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	vl = (*stack)->n;
	*stack = (*stack)->next;
	free(aux);
	(*stack)->n += vl;
}

/**
 * _nop - doesn’t do anything
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subtracts the top element of the stack from the
 *		second top element of the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _sub(stack_t **stack, unsigned int line_number)
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
		_putserr(": can't sub, stack too short\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	vl = (*stack)->n;
	*stack = (*stack)->next;
	free(aux);
	(*stack)->n -= vl;
}

/**
 * _div - divides the second top element of the
 *		stack by the top element of the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _div(stack_t **stack, unsigned int line_number)
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
		_putserr(": can't div, stack too short\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		_putserr("L");
		_putcerr(line_number + '0');
		_putserr(": division by zero\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	vl = (*stack)->n;
	*stack = (*stack)->next;
	free(aux);
	(*stack)->n = (*stack)->n / vl;
}
