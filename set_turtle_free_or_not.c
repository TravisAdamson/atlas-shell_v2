#include "shell.h"

/**
 * set_turtle_free_or_not - frees memory related to command arra
 * @cmdS: The command array to be freed.
 *
 * Return: void
 */
void set_turtle_free_or_not(char **cmdS)
{
	int iter = 0;

	for (iter = 0; cmdS[iter]; iter++)
		cmdS[iter] = NULL;
	if (*cmdS)
		free(*cmdS), *cmdS = NULL;
}
