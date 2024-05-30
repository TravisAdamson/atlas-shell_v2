#include "_sh.h"

/**
 * right_redirect - right redirects
 * @comm: selected command input
 * Return: 0 on success, otherwise returns -1
*/

int right_redirect(c_lst_t *comm)
{
	int fd = 0, l_error = 0;
	int r_out = dup(STDOUT_FILENO);

	if (!comm || !comm->next->comm[0] || comm->next->comm[1])
		return (-1);
	fd = open(comm->next->comm[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		dup2(fd, STDOUT_FILENO);
		l_error = run_comm_branch(comm);
		if (l_error == 13 || l_error == 127)
			run_error(comm->comm, l_error);
		fflush(stdout);
		close(fd);
		dup2(r_out, STDOUT_FILENO);
		close(r_out);
	}
	else
		return (-1);
	return (0);
}

/**
 * right_redirect_2 - double right redirects
 * @comm: selected command input
 * Return: 0 on success, otherwise returns -1
*/

int right_redirect_2(c_lst_t *comm)
{
	int fd = 0, l_error = 0;
	int r_out = dup(STDOUT_FILENO);

	if (!comm || !comm->next->comm[0] || comm->next->comm[1])
		return (-1);
	fd = open(comm->next->comm[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd != -1)
	{
		dup2(fd, STDOUT_FILENO);
		l_error = run_comm_branch(comm);
		if (l_error == 13 || l_error == 127)
			run_error(comm->comm, l_error);
		fflush(stdout);
		close(fd);
		dup2(r_out, STDOUT_FILENO);
		close(r_out);
	}
	else
		return (-1);
	return (0);
}

/**
 * left_redirect - single left redirect
 * @comm: command input
 * Return: 0 on success, otherwise returns -1
*/

int left_redirect(c_lst_t *comm)
{
	int fd = 0, l_error = 0;
	int r_in = dup(STDIN_FILENO);

	if (!comm || !comm->next->comm[0] || comm->next->comm[1])
		return (-1);
	fd = open(comm->next->comm[0], O_RDONLY, 0644);
	if (fd != -1)
	{
		dup2(fd, STDIN_FILENO);
		l_error = run_comm_branch(comm);
		if (l_error)
			run_error(comm->comm, l_error);
		close(fd);
		dup2(r_in, STDIN_FILENO);
		close(r_in);
	}
	else
	{
		if (errno == ENOENT)
		{
			fprintf(
				stderr, "%s: 1: cannot open %s: No such file\n",
				prog.prog_name, comm->next->comm[0]
			);
			run_error(comm->comm, 2);
		}
		return (-1);
	}
	return (0);
}

/**
 * left_redirect_2 - double left redirects
 * @comm: selected command segment input
 * Return: 0 on success, otherwise returns -1
*/

int left_redirect_2(c_lst_t *comm)
{
    (void)comm;
	return (0);
}