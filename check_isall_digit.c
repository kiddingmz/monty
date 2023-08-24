#include "monty.h"

/**
 * isall_digit - check the string if has only digit
 *
 * @str: string
 *
 * Return: int
 */

int isall_digit(const char *str)
{
	while (*str != '\0')
	{
		if (_isdigit(*str) == 1)
			str++;
		else
			return (0);
	}
	return (1);
}
