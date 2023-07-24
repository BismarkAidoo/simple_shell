#include "shell.h"

/**
 * handle_sigint - handles user interrupt signal.
 * @sig: unused.
 * Return: void.
*/
void handle_sigint(int sig __attribute__((unused)))
{
	_putchar('\n');
}
