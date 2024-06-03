#include "shell.h"

/**
 * feed_the_turtle - gets line from input and maintains prompt
 * @prmptStyle: How we want the prompt to look
 * @input: input received from stdin
 * @len: the length of the input from stdin
 *
 * Return: the number of characters read
 */

ssize_t feed_the_turtle(char *prmptStyle, char **input, size_t *len)
{
	ssize_t gotLine = 0, e = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prmptStyle, _str_len(prmptStyle));
	gotLine = getline(input, len, stdin);
	if (gotLine == EOF)
		free(*input), exit(0);
	else if (!gotLine)
		return(-1);
	if (empty_turtle_shell(*input))
		e = -2;
	return (!e ? gotLine : e);
}
