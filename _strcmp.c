#include "monty.h"

/**
 * _strcmp - compare two strings
 *
 * @dest: destine
 * @src: source
 *
 * Return: int
 */

int _strcmp(char *dest, char *src)
{
	size_t i;

	i = 0;
	while (dest[i] || src[i])
	{
		if (dest[i] == src[i])
			i++;
		else
			break;
	}

	if (dest[i] == '\0' && src[i] == '\0')
		return (0);
	return (1);
}
