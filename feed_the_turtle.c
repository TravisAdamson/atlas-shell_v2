#include "shell.h"
/**
 * feed_the_turtle - gets line from input and maintains prompt
 * @prmptStyle: How we want the prompt to look
 * @input: input received from stdin
 * @len: the length of the input from stdin
 *
 * Return: the number of characters read
 */

ssize_t feed_the_turtle(const char *prmptStyle, char **input, size_t *len)
{
	ssize_t gotLine = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prmptStyle, strlen(prmptStyle));
	gotLine = getline(input, len, stdin);
	if (gotLine == EOF)
		return (-1);
	if (gotLine == 0)
		return (1);
	return (gotLine);
}
