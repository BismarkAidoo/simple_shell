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
