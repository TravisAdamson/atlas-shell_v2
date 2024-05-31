#include "_sh.h"

/**
 * _getenv - custom getenv function, retrieves env var value
 * @var_name: name of environmental variable to be retrieved
 * Return: requested environmental variable value
 */

char *_getenv(char *var_name)
{
	int i = 0, f = 0, var_def = 0;
	char *var_eq, *capture = NULL, *env_var = NULL, *env_copy = NULL;
	char *value_str = NULL;
	char *split[MAX_LEN] = { NULL };

	if (!var_name)
		return (NULL);
	var_eq = str_concat(var_name, "=");
	for (i = 0, var_def = _str_len(var_eq); prog.env_lst[i]; i++)
		if (!_strncmp(prog.env_lst[i], var_eq, var_def))
		{
			capture = prog.env_lst[i], f = 1;
			break;
		}
	if (f)
	{
		if (_str_len(capture) != var_def)
		{
			env_var = _strdup(capture), capture = NULL;
			for (i = 0, env_copy = env_var;
				(split[i] = sep(&env_copy, "=")); i++)
				;
			value_str = _strdup(split[1]);
			free(env_var), env_var = NULL;
		}
		free_strvec(split);
	}
	free(var_eq), var_eq = NULL;
	return (value_str ? value_str : NULL);
}

/**
 * env_load - allocates memory for env_list (adjustable copy of environ)
 * Return: 0 upon success, -1 upon memory allocation failure
*/

int __attribute__ ((constructor)) env_load(void)
{
	size_t size = 0;

	if (environ)
	{
		for (; environ[size]; size++)
			;
		prog.env_lst = _calloc(sizeof(char *) * (size + 1), 1);
		if (!prog.env_lst)
			return (-1);
		_memcpy((char *)prog.env_lst, (char *)environ, size * sizeof(char *));
		prog.env_lst_size = prog.env_size = size;
	}
	return (0);
}

/**
 * env_free - frees memory related to env_list (adjustable copy of environ)
*/

void __attribute__ ((destructor)) env_free(void)
{
	size_t added = 0;

	if (prog.env_lst_size > prog.env_size)
		for (added = prog.env_size; prog.env_lst[added]; added++)
			free(prog.env_lst[added]), prog.env_lst[added] = NULL;
	if (prog.env_lst)
		free(prog.env_lst);
}