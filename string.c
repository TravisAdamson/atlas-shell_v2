#include "_sh.h"

/**
 * _strcat - concatenates 2 strings
 * @dest: string 1 to have src appended to end
 * @src: string 2 to append to end of dest
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i_1 = _str_len(dest), i_2 = 0;

	if (!dest || !src)
		return (NULL);
	for (; src[i_2]; i_1++, i_2++)
		dest[i_1] = src[i_2];
	dest[i_1] = '\0';
	return (dest);
}

/**
 * _strcmp - compares 2 strings & shows value upon reaching difference
 * @str1: string 1
 * @str2: string 2
 * Return: value of difference
 */

int _strcmp(char *str1, char *str2)
{
	int i = 0;

	if (!str1 || !str2)
		return (-1);
	while (str1[i] == str2[i] && (str1[i] || str2[i]))
		i++;
	i = (str1[i] - str2[i]);
	return (i);
}

/**
 * _strncmp - compares 2 strings until limit & shows value upon reaching
 *            difference
 * @str1: string 1
 * @str2: string 2
 * @end: numb chars in strings are compared
 * Return: value of difference
 */

int _strncmp(char *str1, char *str2, int end)
{
	int i = 0;

	if (!str1 || !str2)
		return (-1);
	while (
		str1[i] == str2[i] &&
		(str1[i] || str2[i]) &&
		i < end - 1
	)
		i++;
	i = (str1[i] - str2[i]);
	return (i);
}

/**
 * *_strcpy - copies src string to dest
 * @dest: destination memory
 * @src: string to copy terminated by \0
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (!dest || !src)
		return (NULL);
	for (; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _str_len - returns length of input string
 * @str: string to find length
 * Return: number of characters in string
 */

int _str_len(char *str)
{
	int i = 0;

	if (!str)
		return (-1);
	for (; str[i]; i++)
		;
	return (i);
}