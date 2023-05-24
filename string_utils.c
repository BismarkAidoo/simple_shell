#include "string_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

extern char **environ;

/**
 * _strlen - a function to find the
 *		length of a string
 * @s: string to find length
 *
 * Return: Always (0) success
 */

int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
/****** string compare at n byte ********/

/**
 * _strncmp - a function to compare
 *		two strings at n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 *
 * Return: Always (0) success
 */

int _strncmp(const char *s1,
		const char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
	{
		i++;
	}

	if (i == n)
		return (0);

	if (i == n && s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);
	}

	return ((int)(unsigned char)s1[i] -
			(unsigned char)s2[i]);
}

/******* string compare *********/
/**
 * _strcmp - a function to compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}

	return (s1[i] - s2[i]);
}

/*********sting concate*******/
/**
 * _strcat - a function that concatenates two strings
 * @dest: destination for string
 * @src: source of string
 * Return: dest
 */

char *_strcat(char *dest, const char *src)
{
	char *ptr = dest; /* set pointer to end of
			   * destination
			   */

	while (*ptr)
		ptr++;

	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';

	return (dest);
}
/*********string copy **************/

/**
 * _strcpy - a function that copies a string
 * @dest: parameter for argument
 * @src: parameter for argument
 * Return: Always 0.
 */

char *_strcpy(char *dest, const char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';

	return (dest);
}

/******* string duplicate *********/
/**
 * _strdup - a function to duplicate a string
 * @s: string to duplicate
 *
 * Return: a pointer to the new string
 */

char *_strdup(const char *s)
{
	char *new_string;
	int len = _strlen(s);

	new_string = malloc(sizeof(char *) * (len + 1));

	if (new_string != NULL)
	{
		_strcpy(new_string, s);
	}

	return (new_string);
}

/******** Get environment variable ********/
/**
 * _getenv - a function the get the
 *	environment variable of a path
 * @name: name of path
 *
 * Return: NULL
 */

char *_getenv(const char *name)
{
	extern char **environ;
	char **env = environ;
	size_t name_len = _strlen(name);

	while (*env != NULL)
	{
		if (_strncmp(*env, name, name_len
					== 0 && (*env)[name_len] == '='))
		{
			return (&(*env)[name_len + 1]);
		}
		env++;
	}

	return (NULL);
}
/******** set environment ************/
/**
 * _setenv - a function that set value
 *		of an emvironment
 * @name: name of the environment to set
 * @value: value to set
 * @overwrite: a flag indicating whether
 *	to overwrite an existing value
 *
 * Return: Always (0) on succes, (-1) on failure
 */

int _setenv(const char *name, const
		char *value, int overwrite)
{
	size_t name_len = _strlen(name);
	size_t value_len = _strlen(value);
	size_t envName_len = name_len + value_len + 2;
	char *envName;
	int final_env;

	if (name == NULL || value == NULL)
		return (-1);

	if (_getenv(name) != NULL && overwrite == 0)
		return (0);
	envName = malloc(envName_len);

	if (envName == NULL)
		return (-1);

	_strcpy(envName, name);
	envName[name_len] = '=';
	_strcpy(envName + name_len + 1, value);
	final_env = putenv(envName);

	if (final_env != 0)
		free(envName);

	return (final_env);
}
/******** print environment**********************/
/**
 * printEnvironment - a function that prints
 *		the environment of a variable
 *
 * Return: Nothing
 */

void printEnvironment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		size_t len = _strlen(*env);

		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
