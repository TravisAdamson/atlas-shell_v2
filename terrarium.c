#include "_sh.h"

/**
 * see_terrarium - custom getenv function, retrieves env var value
 * @var_name: name of environmental variable to be retrieved
 * Return: requested environmental variable value
 */

char *see_terrarium(char *var_name)
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
		to_shell_w_you(split);
	}
	free(var_eq), var_eq = NULL;
	return (value_str ? value_str : NULL);
}
