#include "shell.h"

/**
 * make_turtlets_too - launches piped command with arguments
 * @comm: arguments to the command
 * Return: 1 upon success, -1 if input or cmd NULL
 */

int make_turtlets_too(c_lst_t *comm)
{
	pid_t child1 = 0, child2 = 0, child3 = 0;
	int f2 = 0, f3 = 0;
	int s = 0, s2 = 0, s3 = 0, i = 0;

	if (!comm)
		return (-1);
	child1 = fork();
	if (child1 == -1)
		perror(comm->new_name), exit(EXIT_FAILURE);
	else if (child1 == 0)
	{
		close(comm_data.pipe_fd[0]);
		dup2(comm_data.pipe_fd[1], STDOUT_FILENO);
		close(comm_data.pipe_fd[1]);
		if (execve(comm->new_name, comm->comm, environ) == -1)
			perror(comm->new_name), exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child1, &s, 0);
		close(comm_data.pipe_fd[1]);
		child2 = fork();
		if (child2 == -1)
			perror(comm->new_name), exit(EXIT_FAILURE);
		else if (child2 == 0)
		{
			close(comm_data.pipe_fd[1]);
			dup2(comm_data.pipe_fd[0], STDIN_FILENO);
			close(comm_data.pipe_fd[0]);
			close(comm_data.pipe2_fd[0]);
			dup2(comm_data.pipe2_fd[1], STDOUT_FILENO);
			close(comm_data.pipe2_fd[1]);
			if (execve(comm->next->new_name, comm->next->comm, environ) == -1)
				perror(comm->new_name), exit(EXIT_FAILURE);
		}
		else
		{
			close(comm_data.pipe_fd[0]);
			close(comm_data.pipe2_fd[1]);
			child3 = fork();
			if (child3 == -1)
				perror(comm->new_name), exit(EXIT_FAILURE);
			else if (child3 == 0)
			{
				close(comm_data.pipe2_fd[1]);
				dup2(comm_data.pipe2_fd[0], STDIN_FILENO);
				close(comm_data.pipe2_fd[0]);
				if (execve(comm->next->next->new_name,
						   comm->next->next->comm, environ) == -1)
					perror(comm->new_name), exit(EXIT_FAILURE);
			}
			else
			{
				close(comm_data.pipe2_fd[0]);
				waitpid(child2, &s2, 0);
				waitpid(child3, &s3, 0);

				f2 = WEXITSTATUS(s2);
				f3 = WEXITSTATUS(s3);
				if (
					(f2 == 2 || f3 == 2) &&
					!isatty(STDIN_FILENO) &&
					comm_data.cmd_ind == comm_data.cmd_ct
				)
					set_turtle_free_or_not(), _exit(0);
			}
		}
	}

	for(i = 0; i < 3; i++)
	{
		if(comm->new_name)
			free(comm->new_name), comm->new_name = NULL;
		comm = comm->next;
	}

	return ((f2 != 0 || f3 != 0) ? -1 : 1);
}

/**
 * turtle_does_too - branches input command, fork_execute if program 
 * 					 exists & can be accessed
 * @comm: vector of arguments retrieved from input
 * Return: 0 success, 1 built-in called, otherwise respective err no.
 */

int turtle_does_too(c_lst_t *comm)
{
	int i = 0, error = 0;
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
		{
			if (!access(f_paths[i], X_OK))
			{
				if (comm->cmd_name)
					free(comm->cmd_name), comm->cmd_name = _strdup(name);
				else
					comm->cmd_name = _strdup(name);
				if (comm->new_name)
					free(comm->new_name), comm->new_name = _strdup(f_paths[i]);
				else
					comm->new_name = _strdup(f_paths[i]);
	
			}
		}
		for (i = 0; f_paths[i]; i++)
			free(f_paths[i]), f_paths[i] = NULL;
		free(f_paths);
	}
	else
	{
		if (!access(name, X_OK))
		{
			if (comm->cmd_name)
				free(comm->cmd_name), comm->cmd_name = _strdup(name);
			else
				comm->cmd_name = _strdup(name);
			if (comm->new_name)
				free(comm->new_name), comm->new_name = _strdup(name);
			else
				comm->new_name = _strdup(name);
		}
	}
	return (0);
}