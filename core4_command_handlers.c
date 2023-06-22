#include "monty.h"

/**
  * handle_pchar - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_pchar(char **args, int *format, int lineno)
{
	char *error_message, *line_str;
	int ascii_char;
	int i;

	(void)args, (void)format;
	if (deque_empty(DEQUE))
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":"
		, "can't pchar, stack empty", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}
	if (*format == STACK_MODE)
	{
		i = DEQUE->tail;
		i = (((i - 1) % DEQUE->size) + DEQUE->size) % DEQUE->size;
	}
	else
	{
		i = DEQUE->head;
	}
	ascii_char = DEQUE->deque[i];
	if (ascii_char > 127 || ascii_char < 0)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":"
		, "can't pchar, value out of range", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	printf("%c\n", ascii_char);
	return (1);
}

/**
  * handle_pstr - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_pstr(char **args, int *format, int lineno)
{
	char *error_message;
	int d_len = deque_len(DEQUE), i, x,
	index = 0;
	char *result;

	(void)args, (void)format, (void)lineno;
	if (deque_empty(DEQUE))
		print_deque(DEQUE);

	result = malloc((d_len + 1) * sizeof(char));
	_memset(result, 0, d_len + 1);
	if (!result)
	{
		error_message = _strddup("Error: malloc failed");
		RAISE(error_message, EXIT_FAILURE);
	}
	x = DEQUE->tail;
	x = (((x - 1) % DEQUE->size) + DEQUE->size) % DEQUE->size;
	for (i = x; i != DEQUE->head
	; i = (((i - 1) % DEQUE->size) + DEQUE->size) % DEQUE->size)
	{
		if (DEQUE->deque[i] <= 0 || DEQUE->deque[i] > 127)
			break;
		result[index++] = DEQUE->deque[i];
	}
	if (DEQUE->deque[i] > 0 && DEQUE->deque[i] <= 127)
		result[index] = DEQUE->deque[i];
	printf("%s\n", result);
	_free_(result);

	return (1);
}

/**
  * handle_rotl - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_rotl(char **args, int *format, int lineno)
{
	int top;

	(void)args, (void)format, (void)lineno;
	if (deque_empty(DEQUE))
		return (1);

	if (*format == STACK_MODE)
	{
		top = dequeue_tail(DEQUE);
		enqueue_head(&DEQUE, top);
		return (1);
	}
	top = dequeue_head(DEQUE);
	enqueue_tail(&DEQUE, top);

	return (1);
}

/**
  * handle_rotr - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_rotr(char **args, int *format, int lineno)
{
	int bottom;

	(void)args, (void)format, (void)lineno;
	if (deque_empty(DEQUE))
		return (1);

	if (*format == STACK_MODE)
	{
		bottom = dequeue_head(DEQUE);
		enqueue_tail(&DEQUE, bottom);
		return (1);
	}
	bottom = dequeue_tail(DEQUE);
	enqueue_head(&DEQUE, bottom);

	return (1);
}

/**
  * handle_stack - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_stack(char **args, int *format, int lineno)
{
	(void)args, (void)format, (void)lineno;
	*format = STACK_MODE;
	return (1);
}
