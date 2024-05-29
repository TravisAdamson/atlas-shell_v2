#include "_sh.h"

/**
 * sep - splits/tokenizes input string per delimiter(s)
 * @data: input string
 * @delim: delimiter(s) by which input is to be divided
 * Return: non-empty tokenized segment from input string, NULL otherwise
 */

char *sep(char **data, char *delim)
{
	char *extract_string = NULL;

	while ((extract_string = _strsep(data, delim)) && !*extract_string)
		;
	return (extract_string);
}

/**
 * _strsep - extracts token from input string delimited by delim
 * @str: string from which token extracted
 * @delim: delimiter by which string to be tokenized
 * Return: element of delimited input as null terminated string
*/

char *_strsep(char **str, const char *delim)
{
	char *begin = *str, *end = NULL;

	if (!begin)
		return (NULL);
	end = begin + _strcspn(begin, delim);
	if (*end)
		*end++ = '\0', *str = end;
	else
		*str = NULL;
	return (begin);
}

/**
 * _strcspn - locate first occurrence of char from ref in str
 * @str: input string
 * @ref: string against which chars from str compared
 * Return: number of characters until ref char
*/

size_t _strcspn(const char *str, const char *ref)
{
	const char *comp1 = NULL, *comp2 = NULL;

	for (comp1 = str; *comp1; ++comp1)
		for (comp2 = ref; *comp2; ++comp2)
			if (*comp1 == *comp2)
				return (comp1 - str);
	return (comp1 - str);
}