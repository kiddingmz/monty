#include "monty.h"

data_t gb_data;

/*
 * check_input - check file
 *
 * @ac: number of arguments
 * @av: arguments vector
 *
 * Return: file
 */

FILE *check_input(int ac, char **av)
{
	FILE *file;

	if (ac == 1 || ac > 2)
	{
		_putserr("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");

	if (file == NULL)
	{
		_putserr("Error: Can't open file ");
		_putserr(av[1]);
		_putchar('\n');
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * main - entry point
 *
 * @ac: number of arguments
 * @av: arguments
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *file;
	size_t size = 256;
	ssize_t nu = 0, line = 1;
	char *buffer = NULL;
	char *args[] = {NULL, NULL};

	file = check_input(ac, av);
	while ((nu = getline(&buffer, &size, file)) != EOF)
	{
		args[0] = _strtok(buffer, " \t\n");
		if (args[0] && args[0][0] != '#')
		{
			f = get_opcodes(args[0]);
			if (f == NULL)
			{
				_putserr("L");
				_putchar('0' + line);
				_putserr(": unknown instruction ");
				_putserr(args[0]);
				_putchar('\n');
				exit(EXIT_FAILURE);
			}
			args[1] = _strtok(NULL, " \t\n");
			if (args[1] != NULL)
				gb_data.gb_nu = args[1];
			f(&gb_data.gb_head, line);
		}
		line++;
	}
	free(buffer);
	free_dlistint(gb_data.gb_head);
	fclose(file);
	return (0);
}
