#include "monty.h"

/**
 * _memmove - move to onother pointer
 *
 * @dest: destine
 * @src: source
 * @n: size
 *
 * Return: string
 *
 */

char *_memmove(char *dest, const char *src, size_t n)
{
	if ((src == NULL) || (dest == NULL))
		return (NULL);
	if ((src < dest) && (dest < src + n))
	{
		dest += n;
		src += n;
		while (n--)
			*--dest = *--src;
	}
	else
	{
		while (n--)
			*dest++ = *src++;
	}
	return (dest);
}
