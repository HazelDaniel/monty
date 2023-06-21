#include "monty.h"

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
		_free_(buff), _index = 0, _len = _strlen(str);
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
			_free_(buff);
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
				_free_(res_buff[i]), _free_(trimmed);
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
		free_str_arr(res_buff, 0), _free_(trimmed);
		return (NULL);
	}
	res_str[res_index] = NULL;
	for (i = 0; i < res_index; i++)
		res_str[i] = res_buff[i];
	_free_(trimmed);

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
