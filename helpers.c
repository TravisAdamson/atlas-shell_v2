#include "_sh.h"

/**
 * remove_all_colons - divides input string into several based on colons present
 * @colon_str: input string to be divided
 * Return: populated string vector upon success, NULL upon mem alloc failure
 */

char **remove_all_colons(char *c_string)
{
	int i = 0;
	char *cpy = NULL, **ps = NULL;

	if (!c_string)
		return (NULL);
	ps = malloc(sizeof(char *) + MAX_LEN);
	if (!ps)
		return (NULL);
	for (cpy = c_string; (ps[i] = sep(&cpy, ":")); i++)
		;
	return (ps);
}

/**
 * make_slash_command - slash + command to all strings in paths
 *                        vector
 * @ps: input vector, to all elements of which slash + command appended
 * @comm: command from main
 * Return: strings concatenated with slash followed by input cmd
 */

char **make_slash_comm(char **ps, char *comm)
{
	int i = 0;
	char slash_string[MAX_LEN] = "/", *slash_comm = NULL, *p = NULL;
	char **res = NULL;

	if (!ps || !comm)
		return (NULL);
	res = _calloc(sizeof(char *) + MAX_LEN, 1);
	if (!res)
		return (NULL);
	slash_string[0] = '/', slash_string[1] = '\0';
	slash_comm = _strcat(slash_string, comm);
	for (; ps[i]; i++)
	{
		p = str_concat(ps[i], slash_comm);
		res[i] = _strdup(p);
		free(p), p = NULL;
	}
	return (res);
}

/**
 * fork_exe - launches command with arguments
 * @name: command name used for error messages
 * @comm: arguments to the command
 * Return: 1 upon success, -1 if input or cmd NULL
 */

int fork_exe(char *name, c_lst_t *comm)
{
	pid_t l = 0;
	int s = 0, f = 0;

	if (!name || !comm)
		return (-1);
	if (comm_data.op_array[comm_data.op_ind] == 0x3)
		return (fork_exe_w_pipe(name, comm));
	l = fork();
	if (l == -1)
		perror(name), exit(EXIT_FAILURE);
	else if (l == 0)
	{
		if (execve(name, comm->comm, environ) == -1)
			perror(name), exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(l, &s, 0);
		f = WEXITSTATUS(s);
		if (
			f == 2 && !isatty(STDIN_FILENO) &&
			comm_data.cmd_ind == comm_data.cmd_ct
		)
			free_comm_data(), _exit(f);
	}
	return (f);
}

/**
 * fork_exe_w_pipe - launches piped command with arguments
 * @name: command name used for error messages
 * @comm: arguments to the command
 * Return: 1 upon success, -1 if input or cmd NULL
 */

int fork_exe_w_pipe(char *name, c_lst_t *comm)
{
	pid_t l = 0;
	int s = 0, f = 0;

	if (!name || !comm)
		return (-1);
	l = fork();
	if (l == -1)
		perror(name), exit(EXIT_FAILURE);
	else if (l == 0)
	{
		close(comm_data.pipe_fd[0]);
		dup2(comm_data.pipe_fd[1], STDOUT_FILENO);
		if (execve(name, comm->comm, environ) == -1)
			perror(name), exit(EXIT_FAILURE);
		close(comm_data.pipe_fd[1]);
	}
	else
	{
		waitpid(l, &s, 0);
		close(comm_data.pipe_fd[1]); /*  */
		dup2(comm_data.pipe_fd[0], STDIN_FILENO);
		close(comm_data.pipe_fd[0]);
		f = WEXITSTATUS(s);
		if (
			f == 2 && !isatty(STDIN_FILENO) &&
			comm_data.cmd_ind == comm_data.cmd_ct
		)
			free_comm_data(), _exit(f);
	}
	return (f);
}

/**
 * str_concat - concatenates two given strings
 * @dest: string to which src is to be concatenated "to"
 * @src: string concatenated to dest "from"
 * Return: pointer to ret_str of concat in resp. freshly allocated memory
 */

char *str_concat(char *dest, char *src)
{
	size_t dest_i = 0, src_i = 0, dest_len = 0, src_len = 0;
	char *ret_str = 0;

	if (!dest)
		dest = "";
	if (!src)
		src = "";
	dest_len = _strlen(dest), src_len = _strlen(src) + 1;
	ret_str = malloc(sizeof(char) * (dest_len + src_len));
	if (!ret_str)
		return (NULL);
	for (; dest[dest_i]; dest_i++)
		ret_str[dest_i] = dest[dest_i];
	for (; src[src_i]; dest_i++, src_i++)
		ret_str[dest_i] = src[src_i];
	ret_str[dest_i] = '\0';
	return (ret_str);
}