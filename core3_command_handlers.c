#include "monty.h"

/**
  * handle_nop - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_nop(char **args, int *format, int lineno)
{
	(void)args, (void)format, (void)lineno;
	return (1);
}

/**
  * handle_sub - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_sub(char **args, int *format, int lineno)
{
	int tail, next_tail, result, head, next_head;
	char *error_message, *line_str;

	(void)args, (void)format;
	if (deque_len(DEQUE) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":"
		, "can't sub, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	if (*format == STACK_MODE)
	{
		tail = dequeue_tail(DEQUE);
		next_tail = dequeue_tail(DEQUE);
		result = next_tail - tail;
		enqueue_tail(&DEQUE, result);
		return (1);
	}
	head = dequeue_head(DEQUE);
	next_head = dequeue_head(DEQUE);
	result = next_head + head;
	enqueue_head(&DEQUE, result);

	return (1);
}

/**
  * handle_div - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_div(char **args, int *format, int lineno)
{
	int tail, next_tail, result;
	char *error_message, *line_str;

	(void)args, (void)format;
	if (deque_len(DEQUE) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":"
		, "can't div, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	tail = dequeue_tail(DEQUE);
	next_tail = dequeue_tail(DEQUE);

	if (tail == 0)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "division by zero", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}
	result = next_tail / tail;
	enqueue_tail(&DEQUE, result);
	return (1);
}

/**
  * handle_mul - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_mul(char **args, int *format, int lineno)
{
	int tail, next_tail, result;
	char *error_message, *line_str;

	(void)args, (void)format;
	if (deque_len(DEQUE) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":"
		, "can't mul, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	tail = dequeue_tail(DEQUE);
	next_tail = dequeue_tail(DEQUE);
	result = next_tail * tail;
	enqueue_tail(&DEQUE, result);
	return (1);
}

/**
  * handle_mod - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_mod(char **args, int *format, int lineno)
{
	int tail, next_tail, result;
	char *error_message, *line_str;

	(void)args, (void)format;
	if (deque_len(DEQUE) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":"
		, "can't mod, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	tail = dequeue_tail(DEQUE);
	next_tail = dequeue_tail(DEQUE);

	if (tail == 0)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "division by zero", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}
	result = next_tail % tail;
	enqueue_tail(&DEQUE, result);
	return (1);
}
