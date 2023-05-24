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

	_setenv("PATH", "/bin", 1);
	pid_t child_pid;
	char *path = _getenv("PATH");

	while (1)
	{
		printPrompt(prompt);
		input = readInput();
		args = handle_args(input);
		if (args[0] == NULL)
		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				exit(0);
			}
			else
			{
				handle_path(args, path);
				child_pid = fork();
				if (child_pid == -1)
				{
					perror("fork");
					exit(1);
				}
				else if (child_pid == 0)
				{
					if (execvp(args[0], args) == -1)
					{
						perror("execvp");
						exit(1);
					}
				}
				else
				{
					int status;
					waitpid(child_pid, &status, 0);
				}
			}
		}
		/* process_exe(args[0]); */
		free(args);
		free(input);
	}

	return (0);
}
