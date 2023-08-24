#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 *
 * @stack: linked list
 * @line_number: line number
 *
 * Return: nothing
 */

void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *aux = NULL;

	if (*stack == NULL ||  (*stack)->next == NULL)
		return;

	aux = *stack;
	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *stack;
	aux->prev = NULL;
	(*stack)->prev = aux;
	*stack = aux;
}
