#include "shell.h"

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

/**
 * _strsep - extracts token from input string delimited by delim
 * @str: string from which token extracted
 * @delim: delimiter by which string to be tokenized
 * Return: element of delimited input as null terminated string
*/

char *_strsep(char **str, const char *delim)
{
	char *begin = *str, *end = NULL;

	if (!begin)
		return (NULL);
	end = begin + _strcspn(begin, delim);
	if (*end)
		*end++ = '\0', *str = end;
	else
		*str = NULL;
	return (begin);
}

/**
 * _strcspn - locate first occurrence of char from ref in str
 * @str: input string
 * @ref: string against which chars from str compared
 * Return: number of characters until ref char
*/

size_t _strcspn(const char *str, const char *ref)
{
	const char *comp1 = NULL, *comp2 = NULL;

	for (comp1 = str; *comp1; ++comp1)
		for (comp2 = ref; *comp2; ++comp2)
			if (*comp1 == *comp2)
				return (comp1 - str);
	return (comp1 - str);
}