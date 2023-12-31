#include "monty.h"

/**
 * get_opcodes - get the correct function
 *
 * @op: opcode
 *
 * Return: pointer to the correct function
 */

void (*get_opcodes(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul},
		{"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl},
		{"rotr", _rotr}, {"stack", _stack},
		{"queue", _queue}, {NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (!_strcmp(instruct[i].opcode, op))
			break;
	}

	return (instruct[i].f);
}
