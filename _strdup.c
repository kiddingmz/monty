#include "monty.h"

/**
 * _strdup - copy string
 *
 * @str: string
 *
 * Return: string
 */

char *_strdup(char *str)
{
	size_t len, i;
	char *string = NULL;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
