#ifndef _MONTY_H
#define _MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_operations - data operations
 *
 * @gb_head: double linked list
 * @gb_nu: argument
 *
 */
typedef struct data_operations
{
	stack_t *gb_head;
	char *gb_nu;
} data_t;

/* share var between source files */
extern data_t gb_data;

/* For linked list */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* opcode functions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);

/* auxiliar functions */
void (*get_opcodes(char *op))(stack_t **stack, unsigned int line_number);
int _putchar(char c);
int _putcerr(char c);
int _isdigit(int c);
void _puts(char *s);
void _putserr(char *s);
int _atoi(char *s);
int _strcmp(char *dest, char *src);
int isall_digit(const char *str);
char *_memmove(char *dest, const char *src, size_t n);
int _isspace(int c);
char **process_args(char *data);
char *_strtok(char *str, const char *delim);
char *_strtrim(char *str);
size_t _strlen(const char *str);
char *_strdup(char *str);
void _free_array(char **av);
#endif
