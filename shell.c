#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - entry point for a unix command line interpreter
 *
 * Return: Always 1 (Success) or 0 (Failure)
 */
int main(void)
{
	char *prompt = "cisfun$";
	char *input = NULL;
	size_t buffer_size = 0;
	ssize_t characters_read;
	pid_t pid;

	while (1)
	{
		printf("%s  ", prompt);
		fflush(stdout);
		characters_read = getline(&input, &buffer_size, stdin);
		if (characters_read == -1)
		{
			if (feof(stdin))
			{
				break;
			}
		}
		if (input[characters_read - 1] == '\n')
		{
			input[characters_read - 1] = '\0';
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* execute program */
			char **args = malloc(2 * sizeof(char *));
			if (args == NULL)
			{
				perror("malloc failed");
				exit(EXIT_FAILURE);
			}
			args[0] = input;
			args[1] = NULL;
			if (execve(args[0], args, environ) == -1)
			{
				/* if execve returns, an error occured */
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(input);
	return (0);
}
