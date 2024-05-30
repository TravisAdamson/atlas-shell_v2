#include "_sh.h"

/**
 * prompt - gets line from input and maintains prompt
 * @prompt_str: How we want the prompt to look
 * @data: input received from stdin
 * @len: the length of the input from stdin
 * Return: the number of characters read,
 *         -1 upon single line break,
 *         -2 if data is empty
 */

ssize_t prompt(char *prompt_str, char **data, size_t *len)
{
	ssize_t getline_err = 0, err = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt_str, _str_len(prompt_str));
	getline_err = getline(data, len, stdin);
	if (getline_err == EOF)
		free(*data), exit(0);
	else if (!getline_err)
		return (-1);
	if (empty_data(*data))
		err = -2, free(*data), *data = NULL;
	return (!err ? getline_err : err);
}

/**
 * empty_data - verifies if data is only space characters
 * @data: input string
 * Return: 0 if length of string equal to number of whitespaces, -1 otherwise
 */

int empty_data(char *data)
{
	int i = 0, spaces = 0;

	if (data)
		for (; data[i]; i++)
			if (
				data[i] == ' ' ||
				data[i] == '\t' ||
				data[i] == '\n' ||
				data[i] == '\r'
			)
				spaces++;
	return (spaces == _str_len(data) ? 1 : 0);
}