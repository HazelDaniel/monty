#include "main.h"

int handle_push(char **args, int *format, int lineno)
{
	char *push_com = NULL, *push_arg = NULL;
	char *error_message = NULL, *line_str;
	int push_item;

	push_com = _strtok(*args, " \t");
	push_arg = _strtok(NULL, " \t");
	if (!push_com || !push_arg)
	{
		error_message = _strddup("Error: malloc failed");
		empty_state_buff(" \t");
		RAISE(error_message, EXIT_FAILURE);
	}

	if (!is_num_str(push_arg))
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "usage: push integer", NULL);
		_free_(line_str);
		empty_state_buff(" \t");
		RAISE(error_message, EXIT_FAILURE);
	}
	push_item = atoi(push_arg);

	if (*format == QUEUE_MODE)
		enqueue_head(&deque, push_item);
	else if (*format == STACK_MODE)
		enqueue_tail(&deque, push_item);

	empty_state_buff(" \t");

	return (1);
}

int handle_pint(char **args, int *format, int lineno)
{
	char *error_message, *line_str;
	int i;

	if (deque_empty(deque))
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "can't pint, stack empty", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}
	i = deque->tail;
	i = (((i - 1) % deque->size) + deque->size) % deque->size;
	printf("%d\n", deque->deque[i]);
	return (1);
}

int handle_pall(char **args, int *format, int lineno)
{
	print_deque(deque);
	return (1);
}

int handle_swap(char **args, int *format, int lineno)
{
	int tail, next_tail;
	char *error_message, *line_str;

	if (deque_len(deque) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "can't swap, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	/*
	 * BUG ALERT:
	 * i am still having misgivings for not swaping
	 * based on the format - i haven't really thought it through
	 * if swap gives me some bugs, then i know who the culprit is
	*/
	tail = dequeue_tail(deque);
	next_tail = dequeue_tail(deque);
	enqueue_tail(&deque, tail);
	enqueue_tail(&deque, next_tail);

	return (1);
}

int handle_add(char **args, int *format, int lineno)
{
	int tail, next_tail, result;
	char *error_message, *line_str;

	if (deque_len(deque) < 2)
	{
		line_str = _itoa(lineno);
		error_message = _strvcat("L", line_str, ":", "can't add, stack too short", NULL);
		_free_(line_str);
		RAISE(error_message, EXIT_FAILURE);
	}

	tail = dequeue_tail(deque);
	next_tail = dequeue_tail(deque);
	result = tail + next_tail;
	enqueue_tail(&deque, result);
	return (1);
}
