#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * printPrompt - a function that prints a prompt
 * @prompt: message to display
 *
 * Return: Nothing
 */
void printPrompt(const char *prompt)
{
	int prompt_length = _strlen(prompt);

	write(1, prompt, prompt_length);
}

/* readInput() */
/**
 * readInput - a function that reads the command input-ted
 *
 * Return: A string
 */
char *readInput()
{
	char *input = NULL;
	size_t buffer_size = 0;
	ssize_t characters_read;

	characters_read = getline(&input, &buffer_size, stdin);
	if (characters_read == -1)
	{
		if (feof(stdin))
		{
			free(input);
			return (NULL);
		}
		else
		{
			perror("Error reading input");
			return (NULL);
		}
	}
	if (input[characters_read - 1] == '\n')
	{
		input[characters_read - 1] = '\0';
	}
	return (input);
}
/* Execution */
/**
 * process_exe - a function that executes the commands given
 * @args: an array of arguments
 *
 * Return: Always (0) success
 */
int process_exe(char *input)
{
	pid_t pid = fork();
	char  **args;

	if (pid == -1)
	{
		perror("Fork failed");
		return (0);
	}
	else if (pid == 0)
	{
		args = handle_args(input);
		if (execve(args[0], args, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);

}
/**
 * main - entry to main function
 *
 * Return: Always (0) success
 *
int main()
{
	char *prompt = "McAnn$  ";
	char *input;

	while (1)
	{
		printPrompt(prompt);
		input = readInput(input);
		process_exe(input);
	}
	free(input);
	return (0);
}
*/
