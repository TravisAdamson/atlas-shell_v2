#include "shell.h"
/**
 * * empty_turtle_shell - determines if it is only space character
 * @input: input string
 *
 * Return: 0 if empty, -1 otherwise.
 */

int empty_turtle_shell(char *input)
{
	int iter = 0;
	size_t num_spaces = 0;

	if (input)
	{
		for (iter = 0; input[iter]; iter++)
		{
			if (input[iter] == '\n' ||
					input[iter] == '\r' ||
					input[iter] == ' ' ||
					input[iter] == '\t')
			{
				num_spaces++;
			}
		}
	}
	return (num_spaces == strlen(input) ? 0 : -1);
}
