#include "_sh.h"

/**
 * build_terrarium - allocates memory for env_list (adjustable copy of environ)
 * Return: 0 upon success, -1 upon memory allocation failure
*/

int __attribute__ ((constructor)) build_terrarium(void)
{
	size_t size = 0;
	size_t i = 0;

	if (environ)
	{
		for (; environ[size]; size++)
			;
		prog.env_lst = _calloc(sizeof(char *) * (size + 1), 1);
		if (!prog.env_lst)
			return (-1);
		for (; i < size; i++)
			prog.env_lst[i] = _strdup(environ[i]);
/* 		_memcpy((char *)prog.env_lst, (char *)environ, size * sizeof(char *)); */
		prog.env_lst[size] = NULL;
		prog.env_lst_size = prog.env_size = size;
	}
	return (0);
}

/**
 * clean_terrarium - frees memory related to env_list (adjustable copy of environ)
*/

void __attribute__ ((destructor)) clean_terrarium(void)
{
	int i = 0;

	while(prog.env_lst[i])
	{
		free(prog.env_lst[i]);
		i++;
	}

	if (prog.env_lst)
		free(prog.env_lst);
}