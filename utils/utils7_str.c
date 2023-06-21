#include "../main.h"

/**
* _strdcat - A function that concatenates two strings
* dynamically
* @dest: a destination string
* @src: a string to append
* description: the first string and only that needs to be
*     dynamically allocated
*     checked
* Return: Always a string
**/
char *_strdcat(char *dest, char *src)
{
	int  ind = 0;
	unsigned int res_len = 0, i, dest_len, src_len;
	char *res = NULL;

	dest_len = _strlen(dest), src_len = _strlen(src);
	res_len = dest_len + src_len;

	res = malloc((res_len) * sizeof(char) + 1);
	if (!res)
		return (res);
	if (res_len == 0)
		return (NULL);
	res[res_len] = '\0';

	for (ind = 0; ind < (int)dest_len; ind++)
		res[ind] = dest[ind];
	for (i = 0; ind < (int)res_len; ind++)
		res[ind] = src[i++];

	return (res);
}

/**
  * is_end_str - the function name
  * @strsub: parameter of type char *.
  * @strsup: parameter of type char *.
  * Return: int .
 */
int is_end_str(char *strsub, char *strsup)
{
	int sub_len = _strlen(strsub), sup_len = _strlen(strsup);
	int i = 0;

	if (sub_len > sup_len)
		return (0);

	if (!sub_len)/* otherwise, sub_len = 0 and i = -1*/
		return (0);

	for (i = sub_len - 1; i >= 0; i--)
	{
		if (strsub[i] != strsup[sup_len - sub_len + i])
			break;
	}
	return (i == -1);
}

/**
 * last_oc_of - a function that returns
 * the last occurrence of a character
 * in a string
 * @str: the string
 * @c: the character
 * Return: int
 **/
int last_oc_of(char *str, char c)
{
	int count = _strlen(str) - 1;

	while (count >= 0 && str[count] != c)
		count--;

	if (str[count] == c)
		return (count);
	else
		return (-1);
}

/**
  * is_start_str - the function name
  * @strsub: parameter of type char *.
  * @strsup: parameter of type char *.
  * Return: int .
 */
int is_start_str(char *strsub, char *strsup)
{
	int sub_len = _strlen(strsub), sup_len = _strlen(strsup);
	int i;

	if (sub_len > sup_len)
		return (0);

	for (i = 0; i < sub_len ; i++)
	{
		if (strsub[i] != strsup[i])
			break;
	}

	return (i == sub_len);
}

int is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
