#include "shell.h"
/**
 * * empty_turtle_shell - determines if it is only space character
 * @input: input string
 *
 * Return: 0 if empty, -1 otherwise.
 */

int empty_turtle_shell(char *input)
{
	int i = 0, num_spaces = 0;

	if (input)
	{
		for (; input[i]; i++)
		{
			if (input[i] == '\n' ||
					input[i] == '\r' ||
					input[i] == ' ' ||
					input[i] == '\t')
			{
				num_spaces++;
			}
		}
	}
	return (num_spaces == _str_len(input) ? 1 : 0);
}
