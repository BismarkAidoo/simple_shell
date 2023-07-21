#include <stdio.h>

/**
 * add_numbers - Add two number and return the result.
 * @x: The first number.
 * @y: The second number.
 *
 * Return: The sum of two numbers.
 */
int add_numbers(int x, int y)
{
	int x = 15;
	int y = 25;
	int result = add_numbers(x, y);

	printf("The sum of %d and %d is %d. \n", x, y, result);
	return (0);
}
