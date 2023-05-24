#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	char a[] = "Antoinette";
	char b[] = "Bismark";
	char buffer[100];
	int length;
	
	length = snprintf(buffer, sizeof(buffer), "%s and %s are the authors of this repository\n", a, b);
	
	write(1, buffer, length);

	return (0);
}
