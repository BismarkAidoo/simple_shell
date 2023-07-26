#include "shell.h"

/**
 * _putchar - prints or displays the string passed to it.
 * @c: a character to print to the stdout
 * Return: a byte
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * env - displays the shell environment.
 * @en: unused.
 * Return: nothing
*/
void env(char *en __attribute__((unused)))
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		i++;
	}
}

/**
 * _puts - function prints strings and prints a new line aftre
 * @str: pointer to strings of character
 *
 * Return: Void
 */

void _puts(char *str)
{
	char try;

	do {
		if (*str != '\0')
		{
			try = *str;
			_putchar(try);
		}
	} while (*str++);
	_putchar('\n');
}
