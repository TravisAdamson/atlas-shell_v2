#include "shell.h"

/**
 * make_turtlets_too - launches piped command with arguments
 * @name: command name used for error messages
 * @comm: arguments to the command
 * Return: 1 upon success, -1 if input or cmd NULL
 */

int make_turtlets_too(char *name, c_lst_t *comm)
{
	pid_t child1 = 0, child2 = 0, child3 = 0;
	int f = 0, f2 = 0, f3 = 0;
	int s = 0, s2 = 0, s3 = 0;

	if (!name || !comm)
		return (-1);
	child1 = fork();
	if (child1 == -1)
		perror(name), exit(EXIT_FAILURE);
	else if (child1 == 0)
	{
		close(comm_data.pipe_fd[0]);
		dup2(comm_data.pipe_fd[1], STDOUT_FILENO);
		close(comm_data.pipe_fd[1]);

		if (execve(name, comm->comm, environ) == -1)
			perror(name), exit(EXIT_FAILURE);
	}
	else
	{
		close(comm_data.pipe_fd[1]);
		
		child2 = fork();

		if (child2 == -1)
			perror(name), exit(EXIT_FAILURE);
		else if (child2 == 0)
		{
			dup2(comm_data.pipe_fd[0], STDIN_FILENO);
			close(comm_data.pipe_fd[0]);

			dup2(comm_data.pipe2_fd[1], STDOUT_FILENO);
			close(comm_data.pipe2_fd[0]);

			if (execve(name, comm->next->comm, environ) == -1)
				perror(name), exit(EXIT_FAILURE);
		}
		else
		{
			child3 = fork();
			if (child3 == -1)
				perror(name), exit(EXIT_FAILURE);
			else if (child3 == 0)
			{
				dup2(comm_data.pipe2_fd[0], STDIN_FILENO);
				close(comm_data.pipe2_fd[0]);
				
				if (execve(name, comm->next->next->comm, environ) == -1)
					perror(name), exit(EXIT_FAILURE);
			}
			else
			{
				close(comm_data.pipe2_fd[0]);

				waitpid(child1, &s, 0);
				waitpid(child2, &s2, 0);
				waitpid(child3, &s3, 0);

				f = WEXITSTATUS(s);
				f2 = WEXITSTATUS(s2);
				f3 = WEXITSTATUS(s3);

				if (
					(f == 2 || f2 == 2 || f3 == 2) &&
					!isatty(STDIN_FILENO) &&
					comm_data.cmd_ind == comm_data.cmd_ct
				)
					set_turtle_free_or_not(), _exit(0);
			}
		}
	}
	return ((f != 0 || f2 != 0 || f3 != 0) ? -1 : 1);
}

/**
 * turtle_does_too - branches input command, fork_execute if program 
 * 					 exists & can be accessed
 * @comm: vector of arguments retrieved from input
 * Return: 0 success, 1 built-in called, otherwise respective err no.
 */

int turtle_does_too(c_lst_t *comm)
{
	int i = 0, t = 0, error = 0, fork_err = 0;
	char **f_paths = NULL, *name = comm->comm[0];

	error = find_nest();
	if (turtle_environment(comm->comm))
		return (1);
	if (access(name, F_OK) == -1)
	{
		if (error == 1)
			return (127);
		f_paths = turtles_nest(name);
		if (!f_paths)
			return (127);
		for (i = 0; f_paths[i]; i++)
			if (!access(f_paths[i], X_OK))
			{
				fork_err = make_turtlets_too(f_paths[i], comm), t = 1;
				break;
			}
		for (i = 0; f_paths[i]; i++)
			free(f_paths[i]), f_paths[i] = NULL;
		free(f_paths);
	}
	else
	{
		if (!access(name, X_OK))
		{
			if (error == 1 && name[0] != '/')
				return (127);
			fork_err = make_turtlet(name, comm), t = 1;
		}
		else if (!access(name, F_OK) && access(name, X_OK) == -1)
			return (13);
	}
	return (!t ? 127 : fork_err ? fork_err : 0);
}