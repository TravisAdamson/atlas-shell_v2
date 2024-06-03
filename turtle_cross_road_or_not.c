#include "shell.h"

/**
 * turtle_cross_road_or_not - launches input command with its arguments
 * @comms: The command to be executed.
 * Return: 0 on success -1 on fail
 */
int turtle_cross_road_or_not(c_lst_t *comms)
{
	int l_error = 0;

	if (!comm_data.op_ct)
	{
		l_error = turtle_does(comms);
		if (l_error == 13 || l_error == 127)
			no_such_turtle(comms->comm, l_error);
	}
	else
		turtle_homing(comms);
	return (0);
}

/**
 * turtle_does - branches input command, fork_execute if program 
 * 					 exists & can be accessed
 * @comm: vector of arguments retrieved from input
 * Return: 0 success, 1 built-in called, otherwise respective err no.
 */

int turtle_does(c_lst_t *comm)
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
				fork_err = make_turtlet(f_paths[i], comm), t = 1;
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

/**
 * find_nest - checks status of PATH & PWD environmental variables
 * Return: 0 if PATH & PWD, 1 if PATH NULL, 2 if PWD NULL
 */

int find_nest(void)
{
	char *check_dir = NULL, *check_pdir = NULL;

	check_dir = _getenv("PATH");
	if (!check_dir)
	{
		free(check_dir), check_dir = NULL;
		return (1);
	}
	if (check_dir)
		free(check_dir), check_dir = NULL;
	check_pdir = _getenv("PWD");
	if (!check_pdir)
	{
		free(check_pdir), check_pdir = NULL;
		return (2);
	}
	if (check_pdir)
		free(check_pdir), check_pdir = NULL;
	return (0);
}

/**
 * proc_path - processes PATH env var for stat/access use
 * @command: command to be appended with slash to individual PATH directories
 * Return: processed PATH elements for use in launch_manager function, NULL
 *         upon malloc failure, input vector unavailable, or PATH variable
 *         empty/unaccessible
 */

char **turtles_nest(char *comm)
{
	int m_size = 0;
	char *p_string = NULL, *d = NULL, **ps = NULL, **s_paths = NULL;

	if (!comm)
		return (NULL);
	p_string = _getenv("PATH");
	if (!p_string)
		return (NULL);
	m_size = turtle_eggs(p_string, comm);
	d = malloc(sizeof(char) * m_size);
	if (!d)
		return (NULL);
	_strcpy(d, p_string);
	ps = clear_debris(d);
	s_paths = find_mate(ps, comm);
	free(ps), free(d), free(p_string);
	return (s_paths);
}

/**
 * turtle_eggs - memory to be allocated when handling PATH
 * @p_str: input string
 * @command: input command from main, necessary for calculation
 * Return: multiplier number for mem alloc calculation
 */

int turtle_eggs(char *p_string, char *comm)
{
	int i = 0, b = 0;

	for (; p_string[i]; i++)
		if (p_string[i] == ':')
			b++;
	b++;
	b *= (_str_len(comm) + 1);
	b += (_str_len(p_string) + 1);
	return (b);
}