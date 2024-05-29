#include "shell.h"

/**
 * print_environment_variables - prints environmental variables
 * @environment_variables: an array of environmental variables
 *
 * Return: 0 upon success, -1 otherwise.
 */
int print_environment_variables(char **environment_variables)
{
	int iter = 0;

	for (; environment_variables != NULL &&
			*environment_variables != NULL; ++environment_variables)
	{
		if (environment_variables == NULL)
			printf("%s", *environment_variables);
		else
			printf("%s\n", *environment_variables);
	}
	return (iter > 0 ? 0 : -1);
}
