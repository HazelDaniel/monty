#include "monty.h"

/**
  * handle_push - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_push(char **args, int *format, int lineno)
{
	char *push_com = NULL, *push_arg = NULL;
	char *error_message = NULL, *line_str;
	int push_item;

	push_com = _strtok(*args, " \t");
	push_arg = _strtok(NULL, " \t");
	if (!push_com || !push_arg)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ": ", "usage: push integer", NULL);
		_free_(line_str), empty_state_buff(" \t");
		RAISE(error_message, EXIT_FAILURE);
	}

	if (!is_num_str(push_arg))
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ": ", "usage: push integer", NULL);
		_free_(line_str), empty_state_buff(" \t");
		RAISE(error_message, EXIT_FAILURE);
	}
	push_item = atoi(push_arg);

	if (*format == QUEUE_MODE)
		enqueue_head(&DEQUE, push_item);
	else if (*format == STACK_MODE)
		enqueue_tail(&DEQUE, push_item);

	empty_state_buff(" \t");

	return (1);
}

/**
  * handle_pint - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_pint(char **args, int *format, int lineno)
{
	char *error_message, *line_str;
	int i;

	(void)args, (void)format, (void)lineno;
	if (deque_empty(DEQUE))
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ": "
		, "can't pint, stack empty", NULL);
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
	printf("%d\n", DEQUE->deque[i]);
	return (1);
}

/**
  * handle_pall - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_pall(char **args, int *format, int lineno)
{
	(void)args, (void)format, (void)lineno;
	print_deque(DEQUE);
	return (1);
}

/**
  * handle_swap - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_swap(char **args, int *format, int lineno)
{
	int tail, next_tail, head, next_head;
	char *error_message, *line_str;

	(void)args, (void)format;
	if (deque_len(DEQUE) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ": "
		, "can't swap, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	/*
	 * BUG ALERT:
	 * i am still having misgivings for not swaping
	 * based on the format - i haven't really thought it through
	 * if swap gives me some bugs, then i know who the culprit is
	 * update - just did
	*/
	if (*format == STACK_MODE)
	{
		tail = dequeue_tail(DEQUE);
		next_tail = dequeue_tail(DEQUE);
		enqueue_tail(&DEQUE, tail);
		enqueue_tail(&DEQUE, next_tail);
		return (1);
	}
	head = dequeue_head(DEQUE);
	next_head = dequeue_head(DEQUE);
	enqueue_head(&DEQUE, head);
	enqueue_head(&DEQUE, next_head);

	return (1);
}

/**
  * handle_add - the function name
  * @args: parameter of type char **.
  * @format: parameter of type int *.
  * @lineno: parameter of type int .
  * Return: int .
 */
int handle_add(char **args, int *format, int lineno)
{
	int tail, next_tail, result, head, next_head;
	char *error_message, *line_str;

	(void)args, (void)format;
	if (deque_len(DEQUE) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ": "
		, "can't add, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	if (*format == STACK_MODE)
	{
		tail = dequeue_tail(DEQUE);
		next_tail = dequeue_tail(DEQUE);
		result = tail + next_tail;
		enqueue_tail(&DEQUE, result);
		return (1);
	}
	head = dequeue_head(DEQUE);
	next_head = dequeue_head(DEQUE);
	result = head + next_head;
	enqueue_head(&DEQUE, result);

	return (1);
}
