#include "monty.h"

/**
 * _isspace - check space in a string
 *
 * @c: char
 *
 * Return: int
 *
 */

int _isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' ||
		c == '\v' || c == '\f')
		return (1);
	return (0);
}
