#include "main.h"

int handle_nop(char **args, int *format, int lineno)
{
	(void)args, (void)format, (void)lineno;
	return (1);
}

int handle_sub(char **args, int *format, int lineno)
{
	int tail, next_tail, result;
	char *error_message, *line_str;

	if (deque_len(deque) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "can't sub, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	tail = dequeue_tail(deque);
	next_tail = dequeue_tail(deque);
	result = next_tail - tail;
	enqueue_tail(&deque, result);
	return (1);
}

int handle_div(char **args, int *format, int lineno)
{
	int tail, next_tail, result;
	char *error_message, *line_str;

	if (deque_len(deque) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "can't div, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	tail = dequeue_tail(deque);
	next_tail = dequeue_tail(deque);

	if (tail == 0)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "division by zero", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}
	result = next_tail / tail;
	enqueue_tail(&deque, result);
	return (1);
}

int handle_mul(char **args, int *format, int lineno)
{
	int tail, next_tail, result;
	char *error_message, *line_str;

	if (deque_len(deque) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "can't mul, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	tail = dequeue_tail(deque);
	next_tail = dequeue_tail(deque);
	result = next_tail * tail;
	enqueue_tail(&deque, result);
	return (1);
}

int handle_mod(char **args, int *format, int lineno)
{
	int tail, next_tail, result;
	char *error_message, *line_str;

	if (deque_len(deque) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "can't mod, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	tail = dequeue_tail(deque);
	next_tail = dequeue_tail(deque);

	if (tail == 0)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "division by zero", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}
	result = next_tail % tail;
	enqueue_tail(&deque, result);
	return (1);
}