#include "monty.h"

/**
 * _putserr - print string error
 *
 * @str: string
 *
 * Return: nothing
 */

void _putserr(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0' && str != NULL; i++)
		_putcerr(str[i]);
}
