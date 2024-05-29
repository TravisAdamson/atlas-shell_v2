#include "_sh.h"

/**
 * empty_data - verifies if data is only space characters
 * @data: input string
 * Return: 0 if length of string equal to number of whitespaces, -1 otherwise
 */

int empty_data(char *data)
{
	int i = 0, spaces = 0;

	if (data)
		for (; data[i]; i++)
			if (
				data[i] == ' ' ||
				data[i] == '\t' ||
				data[i] == '\n' ||
				data[i] == '\r'
			)
				spaces++;
	return (spaces == _strlen(data) ? 1 : 0);
}