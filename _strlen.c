#include "monty.h"

/**
 * _strlen -length of string
 *
 * @str: string
 *
 * Return: unsigned int
 */

size_t _strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
