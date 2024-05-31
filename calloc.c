#include "_sh.h"

/**
 * *_calloc - Allocates an array with malloc
 * @nmemb: Array
 * @size: Size of the given array
 *
 * Return: Pointer to new memmory location
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *point;
	unsigned int i;
	char *insidep;

	i = 0;
	if ((nmemb == 0) || (size == 0))
		return (NULL);
	point = malloc(nmemb * size);
	if (point == NULL)
		return (NULL);
	insidep = point;
	for (i = 0; i < (size * nmemb); i++)
		insidep[i] = '\0';
	return (insidep);
}

/**
 * _memcpy - copy n bytes of src to dest
 * @dest: place where n bytes of src to be copied
 * @src: source, n bytes of which copied to dest
 * @n: amount of src to be copied to dest
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	if (!n)
		return (NULL);
	for (; i != n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _realloc - reallocates memory & copies memory to new allocation
 * @memory: pointer to memory for which space to be reallocated
 * @old_size: size of current allocation
 * @new_size: expected size of new memory allocation
 * Return: pointer to allocated memory, NULL upon allocation failure
 */

void *_realloc(void *memory, size_t old_size, size_t new_size)
{
	void *new_mem = NULL;

	if (!memory)
	{
		new_mem = malloc(new_size);
		if (!new_mem)
			return (NULL);
	}
	else
	{
		if (old_size < new_size)
		{
			new_mem = malloc(new_size);
			if (!new_mem)
				return (NULL);
			_memcpy(new_mem, memory, old_size);
			free(memory);
		}
		else
			new_mem = memory;
	}
	return (new_mem);
}