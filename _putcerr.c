#include "monty.h"

/**
 * _putcerr - print a char error
 *
 * @c: char
 *
 * Return: int
 */

int _putcerr(char c)
{
	return (write(2, &c, 1));
}
