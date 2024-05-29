#include "shell.h"

/**
 * shell_cracked - splits/tokenizes input string per delimiter(s)
 * @input: input
 * @delim: delimiter(s) by which input is to be divided
 *
 * Return: First token of input
 */

char *shell_cracked(char **input, char *delim)
{
	char *cmdT = NULL;

	while ((cmdT = strsep(input, delim)) && !*cmdT)
		;
	return (cmdT);
}
