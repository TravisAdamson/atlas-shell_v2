#include "shell.h"

/**
 * change_working_directory - changes current working directory
 * @path: desired destination working directory
 *
 * Return: 0 upon success, -1 otherwise
 */
int change_working_directory(char *path)
{
	return (chdir(path));
}
