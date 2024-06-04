#include "shell.h"


/**
 * turtle_environment - manages built-in functions & calls them upon matching input
 * @command[0]: command to be verified against list of built-in functions
 * @command[1]: argument to built-in
 * @command: argument vector parsed from input, to be freed when passed to exit
 * Return: 1 if function called, else 0
 */

int turtle_environment(char **comm)
{
	int f = 0;

	if (*comm)
	{
		if (!_strcmp(comm[0], "cd"))
			rehome_turtle(comm[1]), f = 1;
		else if (!_strcmp(comm[0], "env"))
			view_nest(), f = 1;
		else if (!_strcmp(comm[0], "exit"))
			turtle_is_free(comm[1], comm), f = 1;
		else if (!_strcmp(comm[0], "setenv"))
			change_nest(comm[1], comm[2]), f = 1;
		else if (!_strcmp(comm[0], "unsetenv"))
			clear_nest(comm[1]), f = 1;
	}
	return (f);
}

/**
 * rehome_turtle - change current working directory
 * @path: desired destination working directory
 * Return: 0 upon success, -1 otherwise
 */

int rehome_turtle(char *path)
{
	char *home = NULL, *oldpwd = NULL, cwd[MAX_LEN];
	int changed = 0;

	if (!getcwd(cwd, MAX_LEN))
		return (-1);
	if (path)
	{
		if (_str_len(path) == 1 && path[0] == '-')
		{
			oldpwd = _getenv("OLDPWD");
			if (oldpwd)
				cd_assist(oldpwd, &changed),
				printf("%s\n", oldpwd);
			else
				printf("%s\n", cwd);
			free(oldpwd), oldpwd = NULL;
		}
		else
			cd_assist(path, &changed);
	}
	else
	{
		home = _getenv("HOME");
		if (home)
			cd_assist(home, &changed);
		free(home), home = NULL;
	}
	return (changed ? 0 : -1);
}

/**
 * cd_assist - performs chdir & error handling for builtin_cd
 * @go_here: desired working directory
 * @changed: indicates directory changed successfully
 * Return: 0 upon success, -1 if getcwd fails or dir unable to be changed
*/

int cd_assist(char *dest_dir, int *changed)
{
	struct stat buffer;
	char hold_pwd[MAX_LEN];

	if (!getcwd(hold_pwd, MAX_LEN))
		return (-1);
	if (lstat(dest_dir, &buffer) != -1)
	{
		if (!chdir(dest_dir))
			change_nest("OLDPWD", hold_pwd),
			getcwd(hold_pwd, MAX_LEN),
			change_nest("PWD", hold_pwd),
			*changed = 1;
	}
	else
		fprintf(stderr, "%s: 1: cd: can't cd to %s\n", prog.prog_name, dest_dir);
	return (*changed ? 0 : -1);
}

/**
 * view_nest - prints environmental variables
 * Return: 0 upon success, -1 otherwise or if env vars N/A
 */

int view_nest(void)
{
	char **env_var = NULL;
	int count = 0;

	for (env_var = prog.env_lst; *env_var; ++env_var)
		printf("%s\n", *env_var), count++;
	return (count ? 0 : -1);
}

/**
 * turtle_is_free - built-in provision for terminal exit upon command
 * @code: exit code, if desired
 * @comm: argument vector parsed from input, to be freed
 * Return: 0, if exit fails
 */

int turtle_is_free(char *code, char **comm)
{
	int s = 0, inv = 0, i = 0;

	if (code)
	{
		for (; code[i]; i++)
			if (!_isdigit(code[i]))
			{
				inv = 1;
				break;
			}
		s = _atoi(code);
	}
	if (inv || s < 0)
	{
		fprintf(stderr, "./hsh: 1: %s: Illegal number: %s\n", comm[0], code);
		set_turtle_free_or_not();
		exit(2);
	}
	set_turtle_free_or_not();

	if (s == 2 && comm_data.cmd_ct > 1)
		exit(s);

	if (s == 2)
		s = 0;

	exit(s);
	return (0);
}

/**
 * change_nest - built-in provision for setenv command
 * @name: name of environmental variable to be set value
 * @value: value to be assigned to named environmental variable
 * Return: 0 upon success, -1 upon memory allocation failure
 */

int change_nest(char *name, char *val)
{
	size_t i = 0;
	char *val_string = NULL, **env_cpy = NULL;

	if (!name || !val)
		return (-1);
	for (; prog.env_lst[i]; i++)
		if (!_strncmp(prog.env_lst[i], name, _str_len(name)))
			break;
	val_string = malloc(sizeof(char) * (_str_len(name) + _str_len(val) + 2));
	if (!val_string)
		return (-1);
	_strcpy(val_string, name);
	_strcat(val_string, "=");
	_strcat(val_string, val);
	if (prog.env_lst[i])
		_strcpy(prog.env_lst[i], val_string);
	else
	{
		env_cpy = _realloc(
			(char *)prog.env_lst,
			(i) * sizeof(char *),
			(i + 2) * sizeof(char *));
		if (!env_cpy)
			return (-1);
		_memcpy((char *)env_cpy, (char *)environ, i * sizeof(char *));
		prog.env_lst_size++;
		env_cpy[i] = _strdup(val_string);
		env_cpy[i + 1] = NULL;
		prog.env_lst = env_cpy;
	}
	free(val_string), val_string = NULL;
	return (0);
}

/**
 * clear_nest - built-in provision for unsetenv command
 * @name: name of environmental variable to be set value
 * Return: 0 upon success, -1 upon no variable name input
 */

int clear_nest(char *name)
{
	char **env_var = NULL, **shrink = NULL, *temp = NULL;
	size_t var_len = 0, i = 0;

	if (!name)
		return (-1);
	for (env_var = prog.env_lst, var_len = _str_len(name); *env_var; i++)
	{
		if (!_strncmp(*env_var, name, var_len) && (*env_var)[var_len] == '=')
		{
			temp = *env_var;
			shrink = env_var;
			do
				shrink[0] = shrink[1];
			while (*shrink++);
			if (i >= prog.env_size)
				free(temp);
		}
		else
			++env_var;
	}
	return (0);
}