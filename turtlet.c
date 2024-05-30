#include "_sh.h"

/**
 * build_terrarium - allocates memory for env_list (adjustable copy of environ)
 * Return: 0 upon success, -1 upon memory allocation failure
*/

int __attribute__ ((constructor)) build_terrarium(void)
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
 * clean_terrarium - frees memory related to env_list (adjustable copy of environ)
*/

void __attribute__ ((destructor)) clean_terrarium(void)
{
	size_t added = 0;

	if (prog.env_lst_size > prog.env_size)
		for (added = prog.env_size; prog.env_lst[added]; added++)
			free(prog.env_lst[added]), prog.env_lst[added] = NULL;
	if (prog.env_lst)
		free(prog.env_lst);
}