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
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (_isdigit(str[i]) == 1 || (str[i] == '-' && i == 0))
			i++;
		else
			return (0);
	}
	return (1);
}
