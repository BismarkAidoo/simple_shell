#include "shell.h"

/**
 * display_prompt - displays a prompt or prompts the user for input.
 * Return: void or nothing.
 */
void display_prompt(void)
{
	write(1, "$ ", 2);
}
