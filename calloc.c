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