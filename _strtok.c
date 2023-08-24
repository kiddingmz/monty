#include "monty.h"

/**
 * _strtok - breaks a string
 *
 * @str: string
 * @delim: delimiter
 *
 * Return: string
 */

char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *string = NULL;
	const char *c;

	if (str)
		token = str;
	while (*token)
	{
		for (c = delim; *c; ++c)
		{
			if (*token == *c)
				break;
		}
		if (!*c)
		{
			break;
		}
		++token;
	}
	if (!*token)
		return (NULL);
	string = token;

	while (*token)
	{
		for (c = delim; *c; ++c)
		{
			if (*token == *c)
				break;
		}
		if (*c)
			break;
		++token;
	}
	if (*token)
		*token++ = '\0';
	return (string);
}
