#include "monty.h"

/**
  * _trim - a function that trims
  * @str: the string to trim
  * Return: the trimmed string
	* description: checked
 */
char *_trim(char *str)
{
	int pos_start = 0, i = 0, pos_end = _strlen(str) - 1,
	stat = 0;
	char *sp_char = " \t", *res = NULL;

	if (!str || !str[0])
		return (NULL);
	while (str[i] != '\0')
	{
		if (!(in_str(str[i], sp_char)))
			break;
		if (stat == 0)
		{
			stat = 1;
			pos_start = i;
			while ((in_str(str[pos_start], sp_char)))
				pos_start++;
		}
		i++;
	}
	i = pos_end;

	for (; i >= 0 && in_str(str[i], sp_char); i--)
		;
	pos_end = i;

	res = (char *)malloc((pos_end - pos_start + 2) * sizeof(char));
	if (res == NULL)
		return (res);
	for (i = 0, stat = pos_start; stat <= pos_end; stat++)
		res[i++] = str[stat];
	res[pos_end - pos_start + 1] = '\0';


	return (res);
}

/**
 * srch_rpl_newline - a function that searches
 * and replaces the newline characters in a string
 * with a sentinel value followed by a newline
 * @main_str: the address of the string
 * @r: the replacement string containing the sentinel
 * and newline character
 * Return: void
 **/
void srch_rpl_newline(char **main_str, char *r)
{
	char *res = NULL, *tmp, *str_tmp = NULL, *tmp_res = NULL;
	int nl_index;

	if (!*main_str)
		return;
	tmp = _strddup(*main_str);
	res = _strddup(" ");
	str_tmp = tmp;

	while ((nl_index = first_oc_of(tmp, '\n')) != -1)
	{
		tmp[nl_index] = '\0';
		tmp_res = res;
		res = _strvcat(res, tmp, r, NULL);
		_free_(tmp_res);
		tmp += nl_index + 1;
	}
	tmp_res = res;
	res = _strvcat(res, tmp, NULL);
	_free_(str_tmp), _free_(tmp_res);
	_free_(*main_str), *main_str = res;
}

/**
 * first_oc_of - a function that returns
 * the first occurrence of a character
 * in a string
 * @str: the string
 * @c: the character
 * Return: int
 * description: checked
 **/
int first_oc_of(char *str, char c)
{
	int count = 0;

	while (str[count] && str[count] != c)
		count++;

	if (str[count] == c)
		return (count);
	else
		return (-1);
}

/**
 * _strddup - a function that returns a duplicate, dynamically
 * allocated array of characters
 * @src: the source string
 * Return: the duplicated string
 * description: checked
 **/
char *_strddup(char *src)
{
	int i = 0, len = _strlen(src);
	char *res = NULL;

	if (!src)
		return (NULL);
	res = malloc((len + 1));
	if (!res)
		return (res);
	res[len] = '\0';

	for (; src[i]; i++)
		res[i] = src[i];

	return (res);
}

/**
 * _strvcat - a function that concatenates
 * a variable number of strings
 * @first_str: the first string in the parameter
 * list
 * Return: char *
 **/
char *_strvcat(char *first_str, ...)
{
	va_list arg_list;
	char *curr_str, *acc = NULL, *tmp = NULL;

	va_start(arg_list, first_str);
	curr_str = first_str;
	while (curr_str)
	{
		tmp = _strdcat(acc, curr_str);
		_free_(acc), acc = tmp;
		curr_str = va_arg(arg_list, char *);
	}
	va_end(arg_list);

	return (acc);
}
