#include "_sh.c"

static ssize_t prompt(char *prompt_str, char **data, size_t *len);

/**
 * prompt - gets line from input and maintains prompt
 * @prompt_str: How we want the prompt to look
 * @data: input received from stdin
 * @len: the length of the input from stdin
 * Return: the number of characters read,
 *         -1 upon single line break,
 *         -2 if data is empty
 */

static ssize_t prompt(char *prompt_str, char **data, size_t *len)
{
	ssize_t getline_err = 0, err = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt_str, _strlen(prompt_str));
	getline_err = getline(data, len, stdin);
	if (getline_err == EOF)
		free(*data), exit(0);
	else if (!getline_err)
		return (-1);
	if (empty_input(*data))
		err = -2, free(*data), *data = NULL;
	return (!err ? getline_err : err);
}