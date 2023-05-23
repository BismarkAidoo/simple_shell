#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

void printPrompt(char *prompt)
{
	printf("%s", prompt);
}

char *readInput()
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nOfC_read;

	nOfC_read = getline(&lineptr, &n, stdin);

	if (nOfC_read == -1)
	{
		if (feof(stdin))
		{
			free(lineptr);
			return (NULL);
		}
		else
		{
			perror("Error reading input");
			return (NULL);
		}
	}

	if (lineptr[nOfC_read - 1] == '\n')
		lineptr[nOfC_read - 1] = '\0';

	return (lineptr);
}

int process_exe(char *input)
{
	pid_t pid = fork();
	
	if (pid == -1)
	{
		perror("fork failed");
		return (0);
	}
       	else if (pid == 0)
	{
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
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	
	return 0;
}

int main(void)
{
	char *input = readInput();

	printPrompt("Enter a line of text: ");

	if (input != NULL)
	{
		printf("Input: %s\n", input);
		free(input);
	}

	return (0);
}
