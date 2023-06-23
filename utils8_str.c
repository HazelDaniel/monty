#include "monty.h"

/**
  * last_spn_oc - a function that returns the
	* last spanning occurrence a character in a string
	* based on some properties starting at the first index
  * @f: the property as a function
  * @str:  the string
  * Return: int .
 */
int last_spn_oc(int (*f)(char c), char *str)
{
	int count = 0;

	if (!str)
		return (-1);
	while (str[count] && f(str[count]))
		count++;
	count--;

	return (count);
}

/**
 * is_num_str - a function that checks if
 * a string can be coverted to number
 * @str: the input string
 * Return: int
 **/
int is_num_str(char *str)
{
	int x = 0;

	if (!str || _strlen(str) <= 0)
		return (0);
	if (_strlen(str) > 1 && str[0] == 45)
		x = 1;
	if (last_spn_oc(is_digit, str + x) == (int)_strlen(str) - 1 - x)
		return (1);
	return (0);
}

/**
  * dig_len - a function that returns
	* the number of digits an integer has
  * @num: parameter of type int .
  * Return: int .
 */
int dig_len(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
		len++, num1 = num * -1;
	else
		num1 = num;

	while (num1 >= 10)
		len++, num1 /= 10;

	return (len);
}

/**
  * _itoa - a function that converts integer
	* to string
  * @num: parameter of type int .
  * Return: char *.
 */
char *_itoa(int num)
{
	char *buffer;
	int len = dig_len(num);
	unsigned int num1;

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);

	buffer[len] = '\0';

	if (num < 0)
		num1 = -num, buffer[0] = '-';
	else
		num1 = num;

	len--;
	do {
		buffer[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0 && len != -1);

	return (buffer);
}

/**
  * is_word - a function that checks if
	* a character is word (\w)
  * @c: parameter of type char .
  * Return: int .
 */
int is_word(char c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122) || (c == 95) ||
	 (c >= 48 && c <= 57))
		return (1);

	return (0);
}
