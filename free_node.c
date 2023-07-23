#include "shell.h"

/**
 * free_node - frees memory for the shell_cmd data structure or
 * node.
 * @head: double pointer to the head node
 * Return: nothing.
 */
void free_node(shell_cmd *head)
{
	int i = 1;

	free(head->command);
	head->command = NULL;
	while (head->args[i] != NULL)
	{
		free(head->args[i]);
		i++;
	}
	free(head->args);
	head->args = NULL;
	free(head);
}


/**
 * _error - sends error message to standard error.
 * @file: pointer to the name of the calling program.
 * @n: number of the processes or calling processes
 * @cmdname: pointer to the name of the command.
 * Return: void.
 */
void _error(char *file, int n, char *cmdname)
{
	char str[] = ": not found\n";

	write(2, file, strlen(file));
	write(2, ": ", 2);
	print_number(n);
	write(2, ": ", 2);
	write(2, cmdname, strlen(cmdname));
	write(2, &str, strlen(str));
}


/**
 * print_number - prints an integer.
 * @n: integer to print.
 * Return: void
 */

void print_number(int n)
{
	unsigned int k = n;

	if (n < 0)
	{
		n *= -1;
		k = n;
		_putchar_errno('-');
	}

	k /= 10;

	if (k != 0)
		print_number(k);

	_putchar_errno((unsigned int) n % 10 + '0');

}

/**
 * _putchar_errno - prints a character to the standard error
 * @character: a character to print.
 * Return: number of characters written.
 */
int _putchar_errno(char character)
{
	return (write(2, &character, 1));
}
