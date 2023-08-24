#include "monty.h"

/**
 * _puts - print string
 *
 * @str: string
 *
 * Return: nothing
 */

void _puts(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0' && str != NULL; i++)
		_putchar(str[i]);
}
