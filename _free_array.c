#include "monty.h"

/**
 * _free_array - free array
 *
 * @av: array
 *
 * Return: nothing
 */

void _free_array(char **av)
{
	size_t i;

	i = 0;
	while (av[i] != NULL)
		free(av[i++]);
}
