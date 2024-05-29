#include "shell.h"
/**
 * turtle_surgery - parses/tokenizes input into string vector
 * @input: object string
 * @cmdS: destination string vector
 * @delim: delimiter to be fed to splitting/tokenizing function
 *
 * Return: 0 if input parsed to cmdS, -1 otherwise
 */

int turtle_surgery(char *input, char **cmdS, char *delim)
{
	int iter = 0;
	char *cmdT = NULL, *dup = NULL;

	for (dup = input, iter = 0; (cmdT = shell_cracked(&dup, delim)); iter++)
	{
		cmdS[iter] = cmdT;
		if (strncmp("exit", cmdS[0], 4) == 0)
		{
			set_turtle_free_or_not(cmdS);
			if (input)
				free(input);
			exit(st);
		}
		st = 2;
	}
	if (cmdT != NULL)
		cmdT = NULL;
	if (dup != NULL)
		free(dup), dup = NULL;
	return (*cmdS ? 0 : -1);
}
