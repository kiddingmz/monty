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

/**
 * _mod - computes the rest of the division of the second top element
 *		of the stack by the top element of the stack
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _mod(stack_t **stack, unsigned int line_number)
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
		_putserr(": can't mod, stack too short\n");
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
	(*stack)->n %= vl;
}

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (*stack == NULL || stack == NULL)
	{
		_putserr("L");
		_putcerr(line_number + '0');
		_putserr(": can't pchar, stack empty\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}

	ch = (*stack)->n;
	if (ch > 127 && 0 < ch)
	{
		_putserr("L");
		_putcerr(line_number + '0');
		_putserr(": can't pchar, value out of range\n");
		free_dlistint(gb_data.gb_head);
		exit(EXIT_FAILURE);
	}

	_putchar(ch);
	_putchar('\n');
}

/**
 * _pstr - prints the string starting at the top of the stack,
 *		followed by a new line
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *aux;

	aux = *stack;
	while (aux && aux->n > 0 && aux->n < 128)
	{
		_putchar(aux->n);
		aux = aux->next;
	}
	_putchar('\n');
}

/**
 * _rotl - prints the char at the top of the stack, followed by a new line
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;

	if (*stack == NULL ||  (*stack)->next == NULL)
		return;

	aux1 = (*stack)->next;
	aux2 = *stack;
	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = aux2;
	*stack = aux1;
}
