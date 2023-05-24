#include <unistd.h>

/**
 * add - a function that adds two numbers
 * @a: first parameter
 * @b: second parameter
 *
 * Return: Sum of the two numbers
 */

int sum(int a, int b)
{
	return ((a) + (b));
}

/**
 * main - Entry point of the program
 *
 * Return: Always (0) success
 */

int main(void)
{
	int num1 = 3;
	int num2 = 7;
	int result;

	result = add(num1, num2);

	char buffer[100];
	int length = snprintf(buffer, sizeof(buffer),
			"The sum of %d and %d is: %d\n", num1, num2, results);
	write(1, butter, length);

	return (0);
}
