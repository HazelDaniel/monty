#include "../main.h"

/**
 * _memset - a function that sets
 * contigious memory blocks to a value
 * @ptr: the address of the first element in the
 * memory block
 * @val: the value
 * @len: the length of the assignment
 * Return: void
 * description: checked
 **/
void _memset(void *ptr, int val, size_t len)
{
	size_t i;
	char *ptr_mut = (char *)ptr;

	for (i = 0; i < len; i++)
		ptr_mut[i] = val;
}

/**
	* _strtok - a re-implementation of
	* the strtok function.
	* converts input string to tokens
	* @str: parameter of type char *.
	* @delim: the delimiter
	* Return: char *.
	* description: checked
*/
char *_strtok(char *str, char *delim)
{
	static int _index, _len;
	int start, i;
	static char *buff;

	if (str)
	{
		free(buff), buff = NULL, _index = 0, _len = _strlen(str);
		buff = malloc(sizeof(char) * _strlen(str) + 1);
		if (!buff)
			return (NULL);
		_memcpy(str, buff, _len), buff[_len] = '\0';
		for (i = _index; buff[i] && in_str(buff[i], delim); i++)
			buff[i] = '\0';
		start = i;
		for (; buff[i] && !in_str(buff[i], delim); i++)
			;
		for (; buff[i] && in_str(buff[i], delim); i++)
			buff[i] = '\0';
		_index += i;
		return (buff + start);
	}
	else
	{
		if (_index >= _len)
		{
			free(buff), buff = NULL;
			return (NULL);
		}
		start = _index;
		for (i = _index; buff[i] && !in_str(buff[i], delim); i++)
			_index++;
		for (; buff[i] && in_str(buff[i], delim); i++)
			_index++, buff[i] = '\0';
		return (buff + start);
	}
}

/**
 * _splitstr - a function that splits a string
 * into an array of strings based on a delimiter
 * @str: the input string
 * @delim: the delimiter
 * Return: char **
 * description: checked
 **/
char **_splitstr(char *str, char *delim)
{
	char **res_str = NULL, *token, *res_buff[1024] = {NULL},
	*trimmed = _trim(str);
	size_t count = 0, res_index = 0, i = 0;

	if (!trimmed)
		return (NULL);
	token = _strtok(trimmed, delim);
	while (token)
	{
		count = 0;
		while (token[count])
			count++;
		res_buff[res_index] = malloc((count * sizeof(char)) + 1);
		if (!res_buff[res_index])
		{
			for (i = 0; i < res_index; i++)
				free(res_buff[i]), res_buff[i] = NULL, free(trimmed), trimmed = NULL;
			return (NULL);
		}
		res_buff[res_index][count] = '\0';
		for (i = 0; token[i]; i++)
			res_buff[res_index][i] = token[i];
		token = _strtok(NULL, delim);
		res_index++;
	}
	empty_state_buff(delim);
	res_str = malloc((res_index) * sizeof(char *) + sizeof(char *));
	if (res_str == NULL)
	{
		free_str_arr(res_buff, 0), free(trimmed), trimmed = NULL;
		return (NULL);
	}
	res_str[res_index] = NULL;
	for (i = 0; i < res_index; i++)
		res_str[i] = res_buff[i];
	free(trimmed), trimmed = NULL;

	return (res_str);
}
/**
 * _strlen - a function that computes
 * the lenght of a string
 * @str: the string
 * Return: unsigned int
 * description: checked
 **/
unsigned int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len])
		len++;

	return (len);
}

/**
  * in_str - a function that looks up
	* a character in a string and returns
	* a boolean integer if found
  * @c: parameter of type char .
  * @str: parameter of type char *.
  * Return: int .
	* description: checked
 */
int in_str(char c, char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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
		free(tmp_res), tmp_res = NULL;
		tmp += nl_index + 1;
	}
	tmp_res = res;
	res = _strvcat(res, tmp, NULL);
	free(str_tmp), free(tmp_res), tmp_res = NULL;
	free(*main_str), *main_str = res;
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
		free(acc), acc = tmp;
		curr_str = va_arg(arg_list, char *);
	}
	va_end(arg_list);

	return (acc);
}

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
