#include "_sh.h"

/**
 * _atoi - converts string to integer
 * @input_string: input string to be converted
 * Return: integer form of input string
 */

int _atoi(char *input_string)
{
	int i = 0, s = 1, d = 0;
	size_t o = 0;

	for (; input_string[i] != '\0'; i++)
	{
		if (input_string[i] == '-')
			s = -(s);
		for (; input_string[i] >= '0' && input_string[i] <= '9'; i++)
			o = (o * 10) + (input_string[i] - '0'), d = 1;
		if (d)
			break;
	}
	return (o * s);
}

/**
 * _isdigit - checks if character is a digit
 * @chr: input char checked for digitness
 * Return: 1 if digit, else 0
 */

int _isdigit(int chr)
{
	return (chr >= '0' && chr <= '9' ? 1 : 0);
}