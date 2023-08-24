#include "monty.h"

/**
 * _isdigit - chech if is a digit
 *
 * @c: value
 *
 * Return: int
 */

int _isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}
