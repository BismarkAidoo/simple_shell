#include "shell.h"

/**
 * main - entry to main function to execute code
 *
 *
 * Return: Always (0) success
 *

int main(void)
{
	char *input;
	char **args;
	char *prompt = "cisfun$ ";
	char *path = _getenv("PATH");

	_setenv("PATH", "/bin", 1)
	
	while (1)
	{
		printPrompt(prompt);
		input = readInput();
		args = handle_args(input);

		if (args[0] == NULL)
		{
			free(args);
			free(input);
			break;
		}
		 process_exe(args[0]); 
		free(args);
		free(input);
	}
	return (0);
}*/

int main(void)
{
	char *prompt = "McAnn$  ";
	char *input;
	
	while (1)
	{
		printPrompt(prompt);
		input = readInput();
		process_exe(input);
		free(input);
	}
	
	return (0);
}
