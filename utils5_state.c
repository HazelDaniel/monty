#include "monty.h"

/**
 * free_str_arr - a function that frees
 * an array of pointers to characters
 * @str_arr: the array in question
 * @is_dyn: a boolean that holds if
 * the string array was dynamically allocated
 * Return: void
 * description: checked
 **/
void free_str_arr(char **str_arr, int is_dyn)
{
	int i = 0;

	if (!str_arr)
		return;
	for (; str_arr[i]; i++)
	{
		_free_(str_arr[i]);
	}
	if (is_dyn)
		_free_(str_arr);
}

/**
 * empty_state_buff - a function that
 * empties out and frees the internal
 * static buffer of the strtok function
 * @delim: the delimeter
 * Return: void
 **/
void empty_state_buff(char *delim)
{
	while (_strtok(NULL, delim))
		;
}
