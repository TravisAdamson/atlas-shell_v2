#include "shell.h"
/**
 * turtle_or_not - checks if a file exists or is a turtle fact8
 * @file: The file to be checked.
 *
 * Return: 0 if the file exists or is a turtle fact, -1 otherwise.
 */
int turtle_or_not(char *file)
{
	struct stat buffer;

	return (stat(file, &buffer));
}
