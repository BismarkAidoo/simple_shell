#include "shell.h"

/**
 * main - entry to main function to execute code
 *
 *
 * Return: Always (0) success
 */
int main(void)
{
	char *prompt = "McAnn$  ";
	char *input;
	char **args;
	char *path = _getenv("PATH");

	while (1)
	{
		printPrompt(prompt);
		input = readInput();
		process_exe(input);
		args = handle_args(input);
		handle_path(args, path);
		free(input);
	}
	return (0);
}
