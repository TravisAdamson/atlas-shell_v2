#include "shell.h"

/**
 * baby_turtles - splits/tokenizes input string per delimiter(s)
 * @data: input string
 * @delim: delimiter(s) by which input is to be divided
 * Return: non-empty tokenized segment from input string, NULL otherwise
 */

char *baby_turtles(char **data, char *delim)
{
	char *extract_string = NULL;

	while ((extract_string = _strsep(data, delim)) && !*extract_string)
		;
	return (extract_string);
}
